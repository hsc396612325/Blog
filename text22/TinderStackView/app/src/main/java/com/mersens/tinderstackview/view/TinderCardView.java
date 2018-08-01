package com.mersens.tinderstackview.view;

import android.animation.Animator;
import android.content.Context;
import android.os.SystemClock;
import android.text.TextUtils;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AccelerateInterpolator;
import android.view.animation.OvershootInterpolator;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.TextView;

import com.bumptech.glide.Glide;
import com.mersens.tinderstackview.R;
import com.mersens.tinderstackview.entity.User;
import com.mersens.tinderstackview.utils.DensityUtil;


public class TinderCardView extends FrameLayout implements View.OnTouchListener {
    private static final int PADDINGVALUE = 16;
    private static final float CARD_ROTATION_DEGREES = 40.0f;
    public static final int DURATIONTIME = 300;
    private ImageView iv;
    private TextView tv_name;
    private ImageView iv_tips;
    private int padding;
    private float downX;
    private float downY;
    private float newX;
    private float newY;
    private float dX;
    private float dY;
    private float rightBoundary;
    private float leftBoundary;
    private int screenWidth;
    private OnLoadMoreListener listener;

    public TinderCardView(Context context) {
        this(context, null);
    }

    public TinderCardView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public TinderCardView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context);
    }

    public void init(Context context) {

        if (!isInEditMode()) {
            inflate(context, R.layout.cardview, this);
            screenWidth = DensityUtil.getScreenWidth(context);
            leftBoundary = screenWidth * (1.0f / 6.0f); //是否左滑的边界
            rightBoundary = screenWidth * (5.0f / 6.0f);  //是否右滑的边界
            iv = (ImageView) findViewById(R.id.iv);
            tv_name = (TextView) findViewById(R.id.tv_name);
            iv_tips = (ImageView) findViewById(R.id.iv_tips);
            padding = DensityUtil.dip2px(context, PADDINGVALUE);
            setOnTouchListener(this);

        }

    }

    @Override
    public boolean onTouch(final View view, MotionEvent motionEvent) {
        TinderStackLayout tinderStackLayout = ((TinderStackLayout) view.getParent());
        TinderCardView topCard = (TinderCardView) tinderStackLayout.getChildAt(tinderStackLayout.getChildCount() - 1);
        if (topCard.equals(view)) {
            switch (motionEvent.getAction()) {
                case MotionEvent.ACTION_DOWN:
                    downX = motionEvent.getX();
                    downY = motionEvent.getY();
                    view.clearAnimation();
                    return true;
                case MotionEvent.ACTION_MOVE:
                    newX = motionEvent.getX();
                    newY = motionEvent.getY();
                    dX = newX - downX; //手指移动距离
                    dY = newY - downY;
                    float posX = view.getX() + dX;
                    view.setX(view.getX() + dX);  //view的新距离 需求1，卡片随手指的移动而移动
                    view.setY(view.getY() + dY);

                    float rotation = (CARD_ROTATION_DEGREES * (posX)) / screenWidth;
                    int halfCardHeight = (view.getHeight() / 2);
                    if (downY < halfCardHeight - (2 * padding)) {
                        view.setRotation(rotation);  //设置View在Z轴上的旋转角度 需求2，卡片移动过程中，随距离的增大而，选择角度增大
                    } else {
                        view.setRotation(-rotation);
                    }
                    float alpha = (posX - padding) / (screenWidth * 0.3f);
                    if (alpha > 0) { //需求3, 判断手指的移动方向，显示选择/删除图标，同时图标随距离的增大，透明度增加
                        iv_tips.setAlpha(alpha);
                        iv_tips.setImageResource(R.drawable.ic_like);
                    } else {
                        iv_tips.setAlpha(-alpha);
                        iv_tips.setImageResource(R.drawable.ic_nope);

                    }

                    return true;
                case MotionEvent.ACTION_UP:  //4. 手指离开卡片后，根据移动的距离，判断卡片是否移出屏幕，从左边移动还是右边移动
                    if (isBeyondLeftBoundary(view)) {
                        removeCard(view, -(screenWidth * 2)); //移动view.向左边移出屏幕
                    } else if (isBeyondRightBoundary(view)) {
                        removeCard(view, (screenWidth * 2));

                    } else {
                        resetCard(view); //复原view
                    }


                    return true;
                default:
                    return super.onTouchEvent(motionEvent);
            }
        }
        return super.onTouchEvent(motionEvent);

    }

    private boolean isBeyondLeftBoundary(View view) {
        return (view.getX() + (view.getWidth() / 2) < leftBoundary);
    }

    private boolean isBeyondRightBoundary(View view) {
        return (view.getX() + (view.getWidth() / 2) > rightBoundary);
    }

    private void removeCard(final View view, int xPos) {
        view.animate()
                .x(xPos) //x轴移动距离
                .y(0) //y轴移动距离
                .setInterpolator(new AccelerateInterpolator())  //插值器   在动画开始的地方速率改变比较慢，然后开始加速
                .setDuration(DURATIONTIME) //移动距离
                .setListener(new Animator.AnimatorListener() { //监听
                    @Override
                    public void onAnimationStart(Animator animator) {

                    }

                    @Override
                    public void onAnimationEnd(Animator animator) {//移出后回调
                        ViewGroup viewGroup = (ViewGroup) view.getParent();

                        if (viewGroup != null) {
                            viewGroup.removeView(view);

                            int count = viewGroup.getChildCount(); //需求5，增加新卡片
                            if (count == 1 && listener != null) {
                                listener.onLoad();
                            }
                        }


                    }

                    @Override
                    public void onAnimationCancel(Animator animator) {

                    }

                    @Override
                    public void onAnimationRepeat(Animator animator) {

                    }
                });
    }


    private void resetCard(final View view) {

        view.animate()
                .x(0) //x轴移动
                .y(0) //y轴移动
                .rotation(0) //循环次数
                .setInterpolator(new OvershootInterpolator()) //插值器       向前甩一定值后再回到原来位置
                .setDuration(DURATIONTIME);
        iv_tips.setAlpha(0f); //图标隐藏

    }

    public void bind(User u) {  //view加载数据
        if (u == null) {
            return;
        }
        if (!TextUtils.isEmpty(u.getAvatarUrl())) { //加载图片
            Glide.with(iv.getContext())
                    .load(u.getAvatarUrl())
                    .into(iv);
        }
        if (!TextUtils.isEmpty(u.getName())) { //加载名字
            tv_name.setText(u.getName());
        }
    }

    public interface OnLoadMoreListener {
        void onLoad();
    }


    public void setOnLoadMoreListener(OnLoadMoreListener listener) {
        this.listener = listener;
    }
}

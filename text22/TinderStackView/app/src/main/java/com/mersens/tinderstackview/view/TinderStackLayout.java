package com.mersens.tinderstackview.view;

import android.content.Context;
import android.util.AttributeSet;
import android.view.ViewGroup;
import android.view.animation.AnticipateOvershootInterpolator;
import android.widget.FrameLayout;

import com.mersens.tinderstackview.entity.User;
import com.mersens.tinderstackview.utils.DensityUtil;

import java.util.List;



public class TinderStackLayout extends FrameLayout implements TinderCardView.OnLoadMoreListener {
    private ViewGroup.LayoutParams params = null;
    public static final float BASESCALE_X_VALUE = 50.0f;
    public static final int BASESCALE_Y_VALUE = 8;
    public static final int DURATIONTIME = 300;
    private static final int STACK_SIZE = 4;
    private int index = 0;
    private int scaleY;
    private TinderCardView tc;
    private List<User> mList;

    public TinderStackLayout(Context context) {
        this(context, null);
    }

    public TinderStackLayout(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public TinderStackLayout(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init();
    }

    public void init() {
        params = new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        scaleY = DensityUtil.dip2px(getContext(), BASESCALE_Y_VALUE);
    }

    private void addCard(TinderCardView view) {
        int count = getChildCount();
        addView(view, 0, params);
        float scaleX = 1 - (count / BASESCALE_X_VALUE);
        view.animate()
                .x(0)
                .y(count * scaleY)  //需求6，实现层次感
                .scaleX(scaleX)  //水平缩放比例
                .setInterpolator(new AnticipateOvershootInterpolator())
                .setDuration(DURATIONTIME);
    }

    public void setDatas(List<User> list) {
        this.mList = list;
        if (mList == null) {
            return;
        }
        for (int i = index; index < i + STACK_SIZE; index++) {
            tc = new TinderCardView(getContext());
            tc.bind(mList.get(index));
            tc.setOnLoadMoreListener(this);
            addCard(tc);
        }
    }

    @Override
    public void onLoad() {
        for (int i = index; index < i + (STACK_SIZE - 1); index++) {
            if (index == mList.size()) {
                return;
            }
            tc = new TinderCardView(getContext());
            tc.bind(mList.get(index));
            tc.setOnLoadMoreListener(this);
            addCard(tc);
        }
        int childCount = getChildCount();
        for (int i = childCount - 1; i >= 0; i--) {
            TinderCardView tinderCardView = (TinderCardView) getChildAt(i);
            if (tinderCardView != null) {
                float scaleValue = 1 - ((childCount - 1 - i) / 50.0f);
                tinderCardView.animate()
                        .x(0)
                        .y((childCount - 1 - i) * scaleY)
                        .scaleX(scaleValue)
                        .rotation(0)
                        .setInterpolator(new AnticipateOvershootInterpolator())
                        .setDuration(DURATIONTIME);
            }
        }
    }
}

package com.mersens.tinderstackview.activity;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import com.mersens.tinderstackview.R;
import com.mersens.tinderstackview.entity.User;
import com.mersens.tinderstackview.view.TinderStackLayout;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private TinderStackLayout tinderStackLayout;
    private List<User> mList;
    private String names[];
    private String avatarUrls[];

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();
    }

    public void init(){
        mList=new ArrayList<User>();
        names=getResources().getStringArray(R.array.names);
        avatarUrls=getResources().getStringArray(R.array.avatar_urls);
        tinderStackLayout=(TinderStackLayout)findViewById(R.id.tinderStackLayout);
        for(int i=0;i<names.length;i++){
            User user=new User(names[i],avatarUrls[i]);
            mList.add(user);
        }
        tinderStackLayout.setDatas(mList);

    }
}

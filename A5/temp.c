#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#include "include/raylib.h"



int WINHEIGHT=900;
int WINWIDTH=1600;


struct Slider
{
    //defining variables for the slider;
    Rectangle rect;
    int posx;
    int posy;

    float rotation;

};

struct Ball{
    int posx;
    int posy;
    Vector2 vector;

    int vx;
    int vy;

    float rotation;

};

struct Deathwalls{
    int posx;
    int posy;
};

struct Safewalls{
    int posx;
    int posy;
};



void BallMovement(struct Ball *ball,int a){
    
    //static float timer=0.0f;
    //timer+=GetFrameTime()


    if(a%2==0){
        ball->posx+=10;
        if(ball->posx>1600)ball->posx=0;

    }else{
        ball->posx-=10;
        if(ball->posx<0)ball->posx=1600;
    }


}

void Render(struct Slider slider1,struct Slider slider2,struct Ball ball,struct Deathwalls red1,struct Deathwalls red2,struct Safewalls blue1,struct Safewalls blue2){
    
    

    Rectangle recSlider1={slider1.posx-10,slider1.posy+100,20,200};
    Rectangle recSlider2={slider2.posx-10,slider2.posy+100,20,200};
    
    Vector2 vecSlider1={10,200};
    Vector2 vecSlider2={10,200};

    DrawRectangle(800,0,5,900,RAYWHITE);
    
    DrawRectangle(red1.posx,red1.posy,5,900,RED);
    DrawRectangle(red2.posx,red2.posy,5,900,RED);

    DrawRectangle(blue1.posx,blue1.posy,1600,5,BLUE);
    DrawRectangle(blue2.posx,blue2.posy,1600,5,BLUE);


    //this function renders all objects to the screen;
    DrawRectanglePro(recSlider1,vecSlider1,slider1.rotation,RAYWHITE);
    DrawRectanglePro(recSlider2,vecSlider2,slider2.rotation,RAYWHITE);
    

    DrawCircle(ball.posx,ball.posy,10,YELLOW);

}


int main(){
    //initializing the two sliders;
    struct Slider slider1;
    struct Slider slider2;
    
    struct Ball ball;

    struct Deathwalls red1;
    struct Deathwalls red2;

    struct Safewalls blue1;
    struct Safewalls blue2;

    
    int a;
    a=rand();

    //giving Deathwalls values
    red1.posx=0;
    red1.posy=0;
    red2.posx=1595;
    red2.posy=0;
    

    blue1.posx=0;
    blue1.posy=0;
    blue2.posx=0;
    blue2.posy=895;


    //giving slider 1 them values
    slider1.posx=100;
    slider1.posy=450;
    slider1.rotation=0.0f;
    
    

    //giving them slider 2 values;
    slider2.posx=1500;
    slider2.posy=450;
    slider2.rotation=0.0f;

    //giving ball values
    ball.posx=800;
    ball.posy=450;


    InitWindow(WINWIDTH,WINHEIGHT,"PongVer1");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        BallMovement(&ball,a);

        Render(slider1,slider2,ball,red1,red2,blue1,blue2);

        //key strokes

        if(IsKeyDown(KEY_W)){
            slider1.posy-=10;

        }
        if(IsKeyDown(KEY_S)){
            slider1.posy+=10;
        }
        if(IsKeyDown(KEY_UP)){
            slider2.posy-=10;

        }
        if(IsKeyDown(KEY_DOWN)){
            slider2.posy+=10;
        }

        EndDrawing();

    }
}
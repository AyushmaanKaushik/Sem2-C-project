#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "include/raylib.h"
#include "include/utils.h"

int WINHEIGHT=900;
int WINWIDTH=1600;


int main(){
    //initializing elements

    //player1
    struct Slider_pong player1;
    player1.rect.x=100;
    player1.rect.y=450;
    player1.rect.width=20;
    player1.rect.height=200;
    player1.rotation=0.0f;
    player1.lives=5;

    //player2
    struct Slider_pong player2;
    player2.rect.x=1500;
    player2.rect.y=450;
    player2.rect.width=20;
    player2.rect.height=200;
    player2.rotation=0.0f;
    player2.lives=5;

    //Death walls
    Rectangle red1={0,0,5,900};
    Rectangle red2={1595,0,5,900};

    //Safe wallss
    Rectangle blue1={0,0,1600,5};
    Rectangle blue2={0,895,1600,5};

    //ball
    struct Ball_pong ball;
    ball.radius=10;
    ball.pos.x=800;
    ball.pos.y=450;
    ball.velocity.x=5;
    ball.velocity.y=0;
    ball.acceleration.x=0;
    ball.acceleration.y=0;

    struct Bricks_pong bricks[20];
    for(int i=0;i<10;i++){
        bricks[i].rect.x=5;
        bricks[i].rect.y=6+i*90;
        bricks[i].rect.height=85;
        bricks[i].rect.width=20;
        bricks[i].is_active=1;

        bricks[20-i-1].rect.x=1575;
        bricks[20-i-1].rect.y=6+i*90;
        bricks[20-i-1].rect.height=85;
        bricks[20-i-1].rect.width=20;
        bricks[20-i-1].is_active=1;
    }
   

    InitWindow(WINWIDTH,WINHEIGHT,"PongVer3");
    SetTargetFPS(120);
    //mainloop which updates every 
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(CANARY);
            Ballmovement(&ball);
            Pong_check_collisions(&ball,&player1,&player2,red1,red2,blue1,blue2,bricks);
            Render_Pong(player1,player2,red1,red2,blue1,blue2,ball,bricks);
            Check_Inputs(&player1,&player2);
            Render_Lives(&player1,&player2);
            

        EndDrawing();

    }

}
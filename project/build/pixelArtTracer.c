#include <stdio.h>
#include "raylib.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1500
#define PTOOL 1
#define PIPETTE 2
#define ZOOM 3
#define ERASER 4
#define MAX_STR_LEN 25

int onCursorSelect(char toolType[])
{
    BeginDrawing();
    Texture2D outline = LoadTexture("/home/deanritter/raylib/projects/VSCode/pixelArtTracer/raylib/resources/img/selected.png");
    Texture2D backgroundZ = LoadTexture("/home/deanritter/raylib/projects/VSCode/pixelArtTracer/raylib/resources/img/img_one.png");
    int ToolType;
    if(strcmp(toolType,"eraser") == 0)
        ToolType = ERASER;
    else if(strcmp(toolType,"ptool") == 0)
        ToolType = PTOOL;
    else if(strcmp(toolType,"zoom") == 0)
        ToolType = ZOOM;
    else if(strcmp(toolType,"pipette") == 0)
        ToolType = PIPETTE;
    else
        printf("Error incorrect operation selected!");
    /*
     Once cursor hovers over the box, it is highlighted or in some
     meaningful capacity 
    */ 

   switch(ToolType)
   {
    case 1:
        printf("Paint Tool Selected");
        DrawTexture(backgroundZ,0,0,WHITE);
        DrawTexture(outline,42,45,WHITE);
        break;
    case 2:
        printf("Pipette Tool Selected");
        DrawTexture(backgroundZ,0,0,WHITE);
        DrawTexture(outline,660,45,WHITE);        
        break;
    case 3:
        printf("Zoom Tool Selected");
        DrawTexture(outline,380,45,WHITE);
        break;
    case 4:
        printf("Eraser Tool Selected");
        DrawTexture(backgroundZ,0,0,WHITE);
        DrawTexture(outline,915,45,WHITE);
        break;

    EndDrawing();

   }


    return ToolType;
}
void paintTool(int *ptrx, int *ptry)
{
    // Similar to the gimp paint tool BUT only paints one pixel at a time

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && ((*ptrx >= 664 && *ptrx <= 1500) 
    && *ptry >=380 && *ptry <= 1000))
    {
        DrawRectangle(*ptrx,*ptry,10,10,BLACK);
    }

    // FIX: Not sure how to stop the paint function from being called even after a new tool is selected

}

void colorPipetteTool(int *ptrx, int *ptry)
{
     if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        printf("teste~!");
    }

    

}

void zoomTool()
{
    // "Zooms" in on the image, also allows subsequent zoom out tool as well

}

void eraserTool(int *ptrx,int *ptry)
{
   if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        // FIX: Not sure why the pixel is only being drawed to the screen once, and paint tool is still selected.
        DrawRectangle(*ptrx,*ptry,100,100,RED);
    }


}



void saveImage(){}

void UpdateDrawFrame();




void init()
{
  
    /*Draws Images, incorpoate onCursorSelect Method, 
    create rudiementary file explorer system, etc.
    */
   InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pixel Art Tracer");
   SetExitKey(0);
   SetTargetFPS(60);
   bool exitWindow = false;
    Texture2D backgroundZ = LoadTexture("/home/deanritter/raylib/projects/VSCode/pixelArtTracer/raylib/resources/img/img_one.png");
    DrawTexture(backgroundZ,0,0,WHITE);

   while(!exitWindow)
   {
      if ( WindowShouldClose()) exitWindow = true;

      BeginDrawing();
     
      
    
      int mouseX= GetMouseX();
      int mouseY = GetMouseY();
      int *ptrMouseX = &mouseX;
      int *ptrMouseY = &mouseY;

      printf("%d\n",*ptrMouseX);
      printf("%d\n",*ptrMouseY);
      paintTool(ptrMouseX,ptrMouseY);

      
      

      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (*ptrMouseX>200 && *ptrMouseX < 330) && 
      (*ptrMouseY > 250 && *ptrMouseY < 300) )
      {
        onCursorSelect("ptool");
        paintTool(ptrMouseX,ptrMouseY);
    
      }

      
      else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (*ptrMouseX>570 && *ptrMouseX < 690) && 
      (*ptrMouseY > 250 && *ptrMouseY < 330) )
      
      {
        onCursorSelect("zoom");
        zoomTool();
      
      }
   
      else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (*ptrMouseX>850 && *ptrMouseX < 970) && 
      (*ptrMouseY > 250 && *ptrMouseY < 330) )
      
      {
        onCursorSelect("pipette");
        colorPipetteTool(ptrMouseX,ptrMouseY);
       
      }

      else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (*ptrMouseX>1100 && *ptrMouseX < 1200) && 
      (*ptrMouseY > 250 && *ptrMouseY < 330) )
      
      {
        
        onCursorSelect("eraser");
        eraserTool(ptrMouseX,ptrMouseY);
       
      }
         
      EndDrawing();
   }

   CloseWindow();
}


int main(void)
{
    init();

   

    return 0;

}


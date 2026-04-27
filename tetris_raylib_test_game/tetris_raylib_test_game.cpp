#include <raylib.h>
#include "game.h"
#include<iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkBlue = { 44, 44, 127, 255 };
    InitWindow(900, 1240, "raylib tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/BoldsPixels.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false) {
        game.HandleInput();
        if (EventTriggered(0.5)) {
            game.MoveBlockDown();
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(font, "Score", { 665, 50 }, 76, 2, WHITE);
        DrawTextEx(font, "Next", { 670, 350 }, 76, 2, WHITE);
        if (game.gameOver) {
            DrawTextEx(font, "GAME", { 670, 750 }, 76, 2, WHITE);
            DrawTextEx(font, "OVER", { 670, 840 }, 76, 2, WHITE);
        }
        else {
            DrawTextEx(font, "ARAF", { 670, 750 }, 76, 2, WHITE);
            DrawTextEx(font, "ISRAK", { 640, 840 }, 76, 2, WHITE);
        }
        DrawRectangleRounded({ 645, 150, 240, 100 }, 0.1, 6, WHITE);
        
        char scoreText[10];
        sprintf_s(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 76, 2);
        
        DrawTextEx(font, scoreText, { 645 + (240-textSize.x)/2, 160}, 76, 2, BLACK);
        DrawRectangleRounded({ 645, 450, 240, 240 }, 0.1, 6, WHITE);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}

#ifndef  MainHeader_h //중복하여 컴파일
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <assert.h> 
#include <time.h>
#include <mmsystem.h>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;//여기서 부터 
int Miro();
int keeper(int(*map)[36], int X, int Y);//여기까지는 미로 찾기
void CursorView();
void gotoxy(int x, int y);
void textcolor(int colorNum);
int GetKeyDown();//여기서 부터 
void DrawDino(int dinoY);
void DrawTree(int treeX);
int DrawGameOver(const int score);
bool isCollision(const int treeX, const int dinoY);
int Dino();//여기까지는 Dino 게임
void hangman();
int screen();
#endif // ! MainHeader_hpp
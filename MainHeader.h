#ifndef  MainHeader_h //�ߺ��Ͽ� ������
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
using namespace std;//���⼭ ���� 
int Miro();
int keeper(int(*map)[36], int X, int Y);//��������� �̷� ã��
void CursorView();
void gotoxy(int x, int y);
void textcolor(int colorNum);
int GetKeyDown();//���⼭ ���� 
void DrawDino(int dinoY);
void DrawTree(int treeX);
int DrawGameOver(const int score);
bool isCollision(const int treeX, const int dinoY);
int Dino();//��������� Dino ����
void hangman();
int screen();
#endif // ! MainHeader_hpp
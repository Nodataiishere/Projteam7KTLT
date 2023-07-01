#ifndef __snake_h__
#define __snake_h__
//File nay cung dc tao tham khao
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")
#pragma warning (disable: 4996)

//CONSTANT DEFINING
#define MAX_SIZE_SNAKE 40
#define MAX_SIZE_FOOD 4
#define MAX_SPEED 9
#define MAX_ROUND 9
#define ID_STUDENT "19127301201273022012731820127441"

using namespace std;

//STRUCT DEFINING
struct MENU
{
	char* choice;
	char selecting;
};

struct HIGHLENGTH
{
	string name;
	int length;
};

//GLOBAL VARIABLES
extern HIGHLENGTH HighLength[5];
extern HIGHLENGTH NewLength;
extern POINT snake[MAX_SIZE_SNAKE];
extern POINT food[4];
extern POINT a;
extern int INDEX_ID;
extern int CHAR_LOCK;
extern int MOVING;
extern int SPEED;
extern int HEIGH_CONSOLE;
extern int WIDTH_CONSOLE;
extern int FOOD_INDEX;
extern int SIZE_SNAKE;
extern int SIZE_PLUS;
extern int STATE;
extern int ROUND;
extern bool GATE_EXIST;
extern char newgame[];
extern char highlength[];
extern char exitgame[];
extern char yes[];
extern char no[];
extern char ok[];
extern int temp;
extern int win;

//PROTOTYPE
void FixConsoleWindow();
void GotoXY(int x, int y);
bool IsValid(int x, int y);
void GenerateFood();
void ResetData();
void DrawBoard(int x, int y, int width, int height);
void drawbox(int x, int y, int width, int height);
void PrintLogo();
void PrintWin();
void PrintLose();
MENU menugame();
void StartGame();
void ExitGame(thread& t);
void PauseGame(HANDLE t);
void DrawGate();
bool CrashGate();
void Eat();
void BlinkSnake();
void ProcessDead();
void DrawFood();
void DrawSnake();
void DeleteTail();
bool CrashWall();
bool CrashItself();
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void ProcessGate();
void ThreadFunc();
bool ContinueGame();
bool IsExistedFileName(string FileName);
bool IsValidFileName(string FileName);
void DeleteBox();
void SaveData();
void TextColor(int color, char* OutputContent);
void LoadData();
bool IsEmptyHighLengthFile();
void SaveHighLength();
void ResetHighLength();
void InitializeHighLength();
void CreateNewHighLength();
void SortHighLength();
void ShowHighLength();
void InitialGame();

#endif // !__snake_h__

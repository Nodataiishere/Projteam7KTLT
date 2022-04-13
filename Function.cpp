#include "Header.h"

HIGHLENGTH HighLength[5];
HIGHLENGTH NewLength;
POINT snake[MAX_SIZE_SNAKE];
POINT food[4];
POINT a;
int INDEX_ID;
int CHAR_LOCK;
int MOVING;
int SPEED;
int HEIGH_CONSOLE;
int WIDTH_CONSOLE;
int FOOD_INDEX;
int SIZE_SNAKE;
int SIZE_PLUS;
int STATE;
int ROUND;
bool GATE_EXIST;
char newgame[] = "NEW GAME";
char highlength[] = "HIGH SCORE";
char exitgame[] = "EXIT GAME";
char yes[] = "Yes";
char no[] = "No";
char ok[] = "OK";
int temp;
int win;

//Xu ly va cham va hieu ung

bool CrashGate()
{
	POINT head = { snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y };
	if ((head.x == a.x + 1 && head.y == a.y) || (head.x == a.x - 1 && head.y == a.y - 1)
		|| (head.x == a.x && head.y == a.y && CHAR_LOCK == 'S') || (head.x == a.x + 1 && head.y == a.y - 1)
		|| (head.x == a.x - 1 && head.y == a.y))
		return true;
	return false;
}

bool CrashItself()
{
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
		if (snake[i].x == snake[SIZE_SNAKE - 1].x && snake[i].y == snake[SIZE_SNAKE - 1].y)
			return true;
	return false;
}

void BlinkSnake()
{
	for (int j = 0; j < 5; j++)
	{
		Sleep(200);
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			GotoXY(snake[i].x, snake[i].y);
			cout << ID_STUDENT[i];
		}
		Sleep(100);
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			GotoXY(snake[i].x, snake[i].y);
			cout << " ";
		}
	}
}

//Xu ly giao dien chinh (menu) va hop thoai thoat (exit)

void PrintLogo()
{
	int xlogo = (WIDTH_CONSOLE / 2) - 37;
	int ylogo = (HEIGH_CONSOLE / 2) - 10;

	for (int i = 1; i <= 14; i++)
	{
		char Line[] = "  _   _ _   _ _   _ _____ ___ _   _  ____    ____  _   _    _    _  _______ ";
		GotoXY(xlogo, ylogo);
		TextColor(i, Line);

		strcpy(Line, " | | | | | | | \\\ | |_   _|_ _| \\\ | |/ ___|  / ___|| \\\ | |  / \\\  | |/ / ____|");
		GotoXY(xlogo, ylogo + 1);
		TextColor(i, Line);

		strcpy(Line, " | |_| | | | |  \\\| | | |  | ||  \\\| | |  _   \\\___ \\\|  \\\| | / _ \\\ | ' /|  _|  ");
		GotoXY(xlogo, ylogo + 2);
		TextColor(i, Line);

		strcpy(Line, " |  _  | |_| | |\\\  | | |  | || |\\\  | |_| |   ___) | |\\\  |/ ___ \\\| . \\\| |___ ");
		GotoXY(xlogo, ylogo + 3);
		TextColor(i, Line);

		strcpy(Line, " |_| |_|\\\___/|_| \\\_| |_| |___|_| \\\_|\\\____|  |____/|_| \\\_/_/   \\\_\\\_|\\\_\\\_____|");
		GotoXY(xlogo, ylogo + 4);
		TextColor(i, Line);

		strcpy(Line, "  _____ _____    _    __  __     ___ _____ ");
		GotoXY(xlogo + 13, ylogo + 5);
		TextColor(i, Line);

		strcpy(Line, " |_   _| ____|  / \\\  |  \\\/  |   / _ \\\___  |");
		GotoXY(xlogo + 13, ylogo + 6);
		TextColor(i, Line);

		strcpy(Line, "   | | |  _|   / _ \\\ | |\\\/| |  | | | | / / ");
		GotoXY(xlogo + 13, ylogo + 7);
		TextColor(i, Line);

		strcpy(Line, "   | | | |___ / ___ \\\| |  | |  | |_| |/ /  ");
		GotoXY(xlogo + 13, ylogo + 8);
		TextColor(i, Line);

		strcpy(Line, "   |_| |_____/_/   \\\_\\\_|  |_|   \\\___//_/   ");
		GotoXY(xlogo + 13, ylogo + 9);
		TextColor(i, Line);
		Sleep(70);
	}
}
void drawbox(int x, int y, int width, int height)
{
	for (int i = x; i < x + width; ++i) {
		GotoXY(i, y);
		cout << char(196);
		GotoXY(i, y + height);
		cout << char(196);
	}
	for (int i = y; i < y + height; ++i) {
		GotoXY(x, i);
		cout << char(179);
		GotoXY(x + width, i);
		cout << char(179);
	}
	GotoXY(x, y); cout << char(218);
	GotoXY(x, y + height); cout << char(192);
	GotoXY(x + width, y); cout << char(191);
	GotoXY(x + width, y + height); cout << char(217);

}

MENU menugame()
{
	MENU select;

	int xmenu = (WIDTH_CONSOLE / 2) - 5;
	int ymenu = (HEIGH_CONSOLE / 2) + 3;

	PrintLogo();
	for (int i = 0; i <= 2; ++i)
		drawbox(45, 15 + 3 * i, 16, 2);
	GotoXY(xmenu, ymenu);
	TextColor(3, newgame);
	GotoXY(xmenu, ymenu + 3);
	cout << highlength;
	GotoXY(xmenu, ymenu + 6);
	cout << exitgame;

	select.choice = newgame;
	while (true)
	{
		if (select.choice == newgame)
		{
			select.selecting = _getch();
			if ((int)select.selecting == 13)
				break;
			if (select.selecting == 's')
			{
				GotoXY(xmenu, ymenu);
				TextColor(7, newgame);
				GotoXY(xmenu, ymenu + 3);
				TextColor(3, highlength);
				select.choice = highlength;
			}
		}
		if (select.choice == highlength)
		{
			select.selecting = _getch();
			if ((int)select.selecting == 13)
			{
				ShowHighLength();
				break;
			}
			if (select.selecting == 's')
			{
				GotoXY(xmenu, ymenu + 3);
				TextColor(7, highlength);
				GotoXY(xmenu, ymenu + 6);
				TextColor(3, exitgame);
				select.choice = exitgame;
			}
			if (select.selecting == 'w')
			{
				GotoXY(xmenu, ymenu + 3);
				TextColor(7, highlength);
				GotoXY(xmenu, ymenu);
				TextColor(3, newgame);
				select.choice = newgame;
			}
		}
		if (select.choice == exitgame)
		{
			select.selecting = _getch();
			if ((int)select.selecting == 13)
				break;
			if (select.selecting == 'w')
			{
				GotoXY(xmenu, ymenu + 6);
				TextColor(7, exitgame);
				GotoXY(xmenu, ymenu + 3);
				TextColor(3, highlength);
				select.choice = highlength;
			}
		}
	}
	return select;
}

bool ContinueGame()
{
	bool Continue = true;

	int column = 30;
	int row = 7;
	int xgame = (WIDTH_CONSOLE / 2) - 15;
	int ygame = (HEIGH_CONSOLE / 2) - 3;
	MENU select;

	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
	cout << " ";

	for (int i = 0; i < row; i++)
	{
		GotoXY(xgame, ygame + i);
		for (int j = 0; j < column; j++)
		{
			if (i == 0)
				cout << (unsigned char)220;
			else if (i == row - 1)
				cout << (unsigned char)223;
			else if (j == 0 || j == column - 1)
				cout << (unsigned char)219;
			else
				cout << " ";
		}
	}
	PrintLose();
	GotoXY(xgame + 3, ygame + 2);
	cout << "Do you want to play more?";
	GotoXY(xgame + 8, ygame + 4);
	TextColor(3, yes);
	GotoXY(xgame + 20, ygame + 4);
	cout << no;
	select.choice = yes;

	if (temp == 'D' || temp == '13') temp = 'A';

	while (true)
	{
		if (select.choice == yes)
		{
			select.selecting = temp;
			if ((int)select.selecting == 13)
				break;
			if (select.selecting == 'D')
			{
				GotoXY(xgame + 8, ygame + 4);
				TextColor(7, yes);
				GotoXY(xgame + 20, ygame + 4);
				TextColor(3, no);
				select.choice = no;
			}
		}
		if (select.choice == no)
		{
			select.selecting = temp;
			if ((int)select.selecting == 13)
				break;
			if (select.selecting == 'A')
			{
				GotoXY(xgame + 8, ygame + 4);
				TextColor(3, yes);
				GotoXY(xgame + 20, ygame + 4);
				TextColor(7, no);
				select.choice = yes;
			}
		}
	}
	if (select.choice == yes)
		StartGame();
	if (select.choice == no)
		Continue = false;

	return Continue;
}

//Xu ly ve thuc an, ve ran

void DrawFood()
{
	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
	cout << ID_STUDENT[INDEX_ID];
}

void DrawSnake()
{
	for (int i = SIZE_SNAKE; i >= 0; i--)
	{
		char body = ID_STUDENT[SIZE_SNAKE - i - 1];
		GotoXY(snake[i].x, snake[i].y);
		cout << body;
	}
}


void DeleteTail()
{
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		GotoXY(snake[i].x, snake[i].y);
		cout << " ";
	}
}

//Xu ly luu/tai tro choi

bool IsExistedFileName(string FileName)
{
	ifstream f_user(".\\Data\\username.txt");
	string tmp;

	while (f_user >> tmp)
		if (tmp == FileName)
		{
			f_user.close();
			return true;
		}
	f_user.close();
	return false;
}

bool IsValidFileName(string FileName)
{
	for (int i = 0; i < FileName.length(); i++)
		if (FileName[i] == '>' || FileName[i] == '<' || FileName[i] == ':'
			|| FileName[i] == '"' || FileName[i] == '/' || FileName[i] == '\\'
			|| FileName[i] == '|' || FileName[i] == '?' || FileName[i] == '*')
			return false;
	return true;
}

void DeleteBox()
{
	int column = 30;
	int row = 8;
	int xgame = (WIDTH_CONSOLE / 2) - 15;
	int ygame = (HEIGH_CONSOLE / 2) - 3;

	for (int i = 0; i < row; i++)
	{
		GotoXY(xgame, ygame + i);
		for (int j = 0; j < column; j++)
		{
			if (i == 0)
				cout << " ";
			else if (i == row - 1)
				cout << " ";
			else if (j == 0 || j == column - 1)
				cout << " ";
			else
				cout << " ";
		}
	}
}

void SaveData()
{
	string FileName;

	int column = 30;
	int row = 8;
	int xgame = (WIDTH_CONSOLE / 2) - 15;
	int ygame = (HEIGH_CONSOLE / 2) - 3;

	for (int i = 0; i < row; i++)
	{
		GotoXY(xgame, ygame + i);
		for (int j = 0; j < column; j++)
		{
			if (i == 0)
				cout << (unsigned char)220;
			else if (i == row - 1)
				cout << (unsigned char)223;
			else if (j == 0 || j == column - 1)
				cout << (unsigned char)219;
			else
				cout << " ";
		}
	}

	GotoXY(xgame + 9, ygame + 2);
	cout << "Save and Exit";
	GotoXY(xgame + 14, ygame + 5);
	TextColor(3, ok);
	GotoXY(xgame + 3, ygame + 3);
	cout << "Name: ";

	do
	{
		GotoXY(xgame + 9, ygame + 3);
		cin >> FileName;
		GotoXY(xgame + 3, ygame + 4);
		if (IsExistedFileName(FileName))
			cout << "File existed, re-type!";
		if (!IsValidFileName(FileName))
			cout << "Invalid char, re-type!";
		if (FileName.length() > 18)
			cout << "Too long, re-type!";

		if (IsExistedFileName(FileName) || !IsValidFileName(FileName) || FileName.length() > 18)
		{
			GotoXY(xgame + 9, ygame + 3);
			for (int i = 0; i < 18; i++)
				cout << " ";
		}
	} while (IsExistedFileName(FileName) || !IsValidFileName(FileName) || FileName.length() > 18);

	DeleteBox();

	ofstream fo(".\\Data\\" + FileName);

	ofstream f_user;
	f_user.open(".\\Data\\username.txt", ios::app);
	f_user << FileName << endl;
	f_user.close();

	fo << SIZE_SNAKE << " " << SIZE_PLUS << endl;

	for (int i = 0; i < SIZE_SNAKE; i++)
		fo << snake[i].x << " " << snake[i].y << endl;

	fo << FOOD_INDEX << endl;

	fo << food[FOOD_INDEX].x << " " << food[FOOD_INDEX].y << endl;

	if (GATE_EXIST)
		fo << a.x << " " << a.y << endl;
	else
		fo << -1 << " " << -1 << endl;

	fo << INDEX_ID << endl;

	fo << SPEED << endl;

	fo << ROUND << endl;

	fo << MOVING << endl;

	fo << CHAR_LOCK << endl;

	fo << win;

	fo.close();

	NewLength.name = FileName;
	NewLength.length = SIZE_SNAKE + SIZE_PLUS;

	CreateNewHighLength();
	SortHighLength();
}

void LoadData()
{
	string FileName;
	int column = 30;
	int row = 8;
	int xgame = (WIDTH_CONSOLE / 2) - 15;
	int ygame = (HEIGH_CONSOLE / 2) - 3;

	for (int i = 0; i < row; i++)
	{
		GotoXY(xgame, ygame + i);
		for (int j = 0; j < column; j++)
		{
			if (i == 0)
				cout << (unsigned char)220;
			else if (i == row - 1)
				cout << (unsigned char)223;
			else if (j == 0 || j == column - 1)
				cout << (unsigned char)219;
			else
				cout << " ";
		}
	}

	GotoXY(xgame + 11, ygame + 2);
	cout << "Load data";
	GotoXY(xgame + 14, ygame + 5);
	TextColor(3, ok);
	GotoXY(xgame + 3, ygame + 3);
	cout << "Name: ";

	do
	{
		GotoXY(xgame + 9, ygame + 3);
		cin >> FileName;
		if (!IsExistedFileName(FileName))
		{
			GotoXY(xgame + 3, ygame + 4);
			cout << "Not existed user!";
			GotoXY(xgame + 9, ygame + 3);
			for (int i = 0; i < 18; i++)
				cout << " ";
		}
	} while (!IsExistedFileName(FileName));

	DeleteBox();

	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		GotoXY(snake[i].x, snake[i].y);
		cout << " ";
	}

	ifstream fi(".\\Data\\" + FileName);

	fi >> SIZE_SNAKE >> SIZE_PLUS;

	GotoXY(8, HEIGH_CONSOLE);
	cout << SIZE_SNAKE + SIZE_PLUS;

	for (int i = 0; i < SIZE_SNAKE; i++)
		fi >> snake[i].x >> snake[i].y;

	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);

	fi >> FOOD_INDEX;
	cout << " ";
	fi >> food[FOOD_INDEX].x >> food[FOOD_INDEX].y;

	fi >> a.x >> a.y;
	if (a.x != -1 && a.y != -1)
	{
		GotoXY(a.x + 1, a.y);
		cout << (unsigned char)223;
		GotoXY(a.x - 1, a.y - 1);
		cout << (unsigned char)219;
		GotoXY(a.x, a.y);
		cout << (unsigned char)223;
		GotoXY(a.x + 1, a.y - 1);
		cout << (unsigned char)219;
		GotoXY(a.x - 1, a.y);
		cout << (unsigned char)223;
		GATE_EXIST = true;
	}

	fi >> INDEX_ID;

	fi >> SPEED;

	fi >> ROUND;

	fi >> MOVING;

	fi >> CHAR_LOCK;

	fi >> win;

	fi.close();
}

//Xu ly nguyen do dai snake va khi an xong food o mot cap

void DrawGate()
{
	do
	{
		a.x = rand() % (WIDTH_CONSOLE - 22) + 2;
		a.y = rand() % (HEIGH_CONSOLE - 4) + 3;
	} while (!IsValid(a.x, a.y) || !IsValid(a.x - 1, a.y) || !IsValid(a.x + 1, a.y)
		|| !IsValid(a.x - 1, a.y - 1) || !IsValid(a.x + 1, a.y - 1));

	GotoXY(a.x + 1, a.y);
	cout << (unsigned char)223;
	GotoXY(a.x - 1, a.y - 1);
	cout << (unsigned char)219;
	GotoXY(a.x, a.y);
	cout << (unsigned char)223;
	GotoXY(a.x + 1, a.y - 1);
	cout << (unsigned char)219;
	GotoXY(a.x - 1, a.y);
	cout << (unsigned char)223;

	GATE_EXIST = true;
}

void ProcessGate()
{
	if (!GATE_EXIST)
		DrawFood();
	if (snake[SIZE_SNAKE - 1].x == a.x && snake[SIZE_SNAKE - 1].y == a.y && GATE_EXIST && CHAR_LOCK == 'W')
	{
		SIZE_SNAKE--;
		SIZE_PLUS++;
	}


	GotoXY(WIDTH_CONSOLE - 6, 3);
	cout << ROUND;

	if (SIZE_SNAKE == 0)
	{
		GotoXY(a.x + 1, a.y);
		cout << " ";
		GotoXY(a.x - 1, a.y - 1);
		cout << " ";
		GotoXY(a.x, a.y);
		cout << " ";
		GotoXY(a.x + 1, a.y - 1);
		cout << " ";
		GotoXY(a.x - 1, a.y);
		cout << " ";

		GATE_EXIST = false;

		win++;
		ROUND++;
		SPEED++;
		SIZE_SNAKE = 4 * ROUND;
		SIZE_PLUS = 0;

		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			snake[i].x = a.x;
			snake[i].y = a.y;
		}

		snake[SIZE_SNAKE - 1].x = a.x;
		snake[SIZE_SNAKE - 1].y = a.y + 1;
	}
}

void PrintWin()
{
	int xwinner = (WIDTH_CONSOLE / 2) - 12;
	int ywinner = (HEIGH_CONSOLE / 2) - 3;
	system("cls");
	int i = 1;
	while (true)
	{
		char Line1[] = " __        _____ _   _ ";
		GotoXY(xwinner, ywinner);
		TextColor(i, Line1);
		strcpy(Line1, " \\\ \\\      / /_ _| \\\ | |");
		GotoXY(xwinner, ywinner + 1);
		TextColor(i, Line1);
		strcpy(Line1, "  \\\ \\\ /\\\ / / | ||  \\\| |");
		GotoXY(xwinner, ywinner + 2);
		TextColor(i, Line1);
		strcpy(Line1, "   \\\ V  V /  | || |\\\  |");
		GotoXY(xwinner, ywinner + 3);
		TextColor(i, Line1);
		strcpy(Line1, "    \\\_/\\\_/  |___|_| \\\_|");
		GotoXY(xwinner, ywinner + 4);
		TextColor(i, Line1);
		i++;
		if (i == 14)
			i = 1;
		Sleep(72);
	}
}

void PrintLose()
{
	int xwinner = (WIDTH_CONSOLE / 2) - 12;
	int ywinner = (HEIGH_CONSOLE / 2) - 3;
	system("cls");
	int i = 1;
	int x = 1;
	while (true)
	{
		char Line1[] = "  _     ___  ____  _____ ";
		GotoXY(xwinner, ywinner);
		TextColor(i, Line1);
		strcpy(Line1, " | |   / _ \\\/ ___|| ____|");
		GotoXY(xwinner, ywinner + 1);
		TextColor(i, Line1);
		strcpy(Line1, " | |  | | | \\\___ \\\|  _|  ");
		GotoXY(xwinner, ywinner + 2);
		TextColor(i, Line1);
		strcpy(Line1, " | |__| |_| |___) | |___ ");
		GotoXY(xwinner, ywinner + 3);
		TextColor(i, Line1);
		strcpy(Line1, " |_____\\\___/|____/|_____|");
		GotoXY(xwinner, ywinner + 4);
		TextColor(i, Line1);
		i++;
		if (i == 14)
			i = 1;
		Sleep(72);
		++x;
		if (x == 40)
			break;
	}
	system("cls");
}

//Xu ly top 5 HIGH LENGTH
bool IsEmptyHighLengthFile()
{
	ifstream fi;
	string name;
	int length;

	fi.open(".\\Data\\highlength.txt");
	if (fi >> name >> length)
	{
		fi.close();
		return false;
	}

	fi.close();
	return true;
}

void SaveHighLength()
{
	remove(".\\Data\\highlength.txt");

	ofstream fo;
	fo.open(".\\Data\\highlength.txt");

	for (int i = 0; i < 4; i++)
		fo << HighLength[i].name << " " << HighLength[i].length << endl;
	fo << HighLength[4].name << " " << HighLength[4].length;

	fo.close();
}

void ResetHighLength()
{
	for (int i = 0; i < 5; i++)
	{
		HighLength[i].name = "[NONE]";
		HighLength[i].length = 4;
	}
	SaveHighLength();
}

void InitializeHighLength()
{
	if (!IsEmptyHighLengthFile())
	{
		string name;
		int length;

		ifstream fi;
		fi.open(".\\Data\\highlength.txt");

		int i = 0;

		while (fi >> name >> length)
		{
			HighLength[i].name = name;
			HighLength[i].length = length;
			i++;
		}

		fi.close();
	}
	else
		ResetHighLength();
}

void CreateNewHighLength()
{
	int minLength = HighLength[0].length;
	int index = 0;
	for (int i = 0; i < 5; i++)
	{
		if (HighLength[i].name == "[NONE]")
		{
			minLength = HighLength[i].length;
			index = i;
			break;
		}
		else if (HighLength[i].length < minLength)
		{
			minLength = HighLength[i].length;
			index = i;
		}
	}

	if (NewLength.length > minLength || (NewLength.length == 4 && HighLength[index].name == "[NONE]"))
	{
		HighLength[index].name = NewLength.name;
		HighLength[index].length = NewLength.length;
	}
}

void SortHighLength()
{
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			if (HighLength[i].length < HighLength[j].length)
			{
				string name = HighLength[i].name;
				HighLength[i].name = HighLength[j].name;
				HighLength[j].name = name;

				int length = HighLength[i].length;
				HighLength[i].length = HighLength[j].length;
				HighLength[j].length = length;
			}
	SaveHighLength();
}

void ShowHighLength()
{
	ifstream fi;
	fi.open(".\\Data\\highlength.txt");

	string name;
	int length;

	system("cls");

	int column = 31;
	int row = 9;
	int xHighLength = (WIDTH_CONSOLE / 2) - 15;
	int yHighLength = (HEIGH_CONSOLE / 2) - 4;

	for (int j = 0; j < row; j++)
	{
		GotoXY(xHighLength, yHighLength + j);
		for (int k = 0; k < column; k++)
		{
			if (j == 0)
				cout << (unsigned char)220;
			else if (j == 2 && k != 0 && k != column - 1)
				cout << "*";
			else if (j == row - 1)
				cout << (unsigned char)223;
			else if (k == 0 || k == column - 1)
				cout << (unsigned char)219;
			else
				cout << " ";
		}
	}

	while (true)
	{
		GotoXY(xHighLength + 10, yHighLength + 1);
		cout << "HIGH SCORE";

		int i = 0;

		while (fi >> name >> length)
		{
			GotoXY(xHighLength + 4, yHighLength + i + 3);
			cout << "#" << i + 1 << ". ";
			GotoXY(xHighLength + 8, yHighLength + i + 3);
			cout << name;
			GotoXY(xHighLength + 27, yHighLength + i + 3);
			cout << length;
			i++;
		}

		if (_kbhit())
			break;
	}
	fi.close();
}

//Mot so ham khac

void TextColor(int color, char* OutputContent)
{
	static int __BACKGROUND;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

	GetConsoleScreenBufferInfo(h, &csbiInfo);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (__BACKGROUND << 4));

	cout << OutputContent;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 + (__BACKGROUND << 4));
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void FixConsoleWindow()
{
	RECT ConsoleRect;
	HWND consoleWindow = GetConsoleWindow();
	GetWindowRect(consoleWindow, &ConsoleRect);
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	MoveWindow(consoleWindow, ConsoleRect.left, ConsoleRect.top, 800, 500, TRUE);
}

void InitialGame()
{
	system("title Snake");
	FixConsoleWindow();
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	WIDTH_CONSOLE = csbi.srWindow.Right - csbi.srWindow.Left;
	HEIGH_CONSOLE = csbi.srWindow.Bottom - csbi.srWindow.Top - 1;

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);

	STATE = 0;
}


bool IsValid(int x, int y)
{
	for (int i = 0; i < SIZE_SNAKE; i++)
		if (snake[i].x == x && snake[i].y == y)
			return false;
	return true;
}

void ResetData()
{
	win = 0;
	ROUND = 1;
	GATE_EXIST = false;
	INDEX_ID = 4;
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1; FOOD_INDEX = 0, SIZE_SNAKE = 4;
	SIZE_PLUS = 0;

	snake[0] = { WIDTH_CONSOLE / 2 - 2, HEIGH_CONSOLE / 2 };
	snake[1] = { WIDTH_CONSOLE / 2 - 1, HEIGH_CONSOLE / 2 };
	snake[2] = { WIDTH_CONSOLE / 2, HEIGH_CONSOLE / 2 };
	snake[3] = { WIDTH_CONSOLE / 2 + 1, HEIGH_CONSOLE / 2 };

	GenerateFood();
}

void DrawBoard(int x, int y, int width, int height)
{
	for (int i = 0; i < width + 1; i++)
	{
		GotoXY(x + i, y);
		cout << (unsigned char)223;
		GotoXY(x + width - i - 1, y + height - 1);
		cout << (unsigned char)220;
		Sleep(0);
	}
	for (int i = 0; i < height; i++)
	{
		GotoXY(x + width - 19, y + height - i - 1);
		cout << (unsigned char)219;
		GotoXY(x, i);
		cout << (unsigned char)219;
		Sleep(0);
	}
	GotoXY(width - 14, 2);
	cout << "Length: " << SIZE_SNAKE;
	GotoXY(width - 14, 3);
	cout << "Round:  " << ROUND;
	char Line[] = "MOVE SNAKE";
	GotoXY(width - 15, 5);
	TextColor(6, Line);
	GotoXY(width - 14, 6);
	cout << "W : Up ";
	GotoXY(width - 14, 7);
	cout << "S : Down ";
	GotoXY(width - 14, 8);
	cout << "D : Right ";
	GotoXY(width - 14, 9);
	cout << "A : Left ";
	GotoXY(0, height + 1);
	cout << "Pause : P \t Save : L \t Load: T \t Force exit: Esc";
}


void StartGame()
{
	system("cls");

	ResetData();

	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
	STATE = 1;
	PlaySound(L".\\Resource\\main.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void ExitGame(thread& t)
{
	system("cls");
	t.detach();
}

void PauseGame(HANDLE t)
{
	SuspendThread(t);
}

void ProcessDead()
{
	STATE = 0;
	PlaySound(L".\\Resource\\die.wav", NULL, SND_ASYNC);
	BlinkSnake();
}

void GenerateFood()
{
	int x, y;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX_SIZE_FOOD; i++)
	{
		do
		{
			x = rand() % (WIDTH_CONSOLE - 25) + 3;
			y = rand() % (HEIGH_CONSOLE - 5) + 3;
		} while (IsValid(x, y) == false);
		food[i] = { x, y };
	}
}

void Eat()
{
	snake[SIZE_SNAKE] = food[FOOD_INDEX];

	SIZE_SNAKE++;
	INDEX_ID++;
	GotoXY(WIDTH_CONSOLE - 6, 2);
	cout << SIZE_SNAKE;

	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		DrawGate();
		FOOD_INDEX = 0;
		GenerateFood();
	}
	else
		FOOD_INDEX++;
}

bool CrashWall()
{
	if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE - 19
		|| snake[SIZE_SNAKE - 1].x == 2
		|| snake[SIZE_SNAKE - 1].y + 1 == HEIGH_CONSOLE - 1
		|| snake[SIZE_SNAKE - 1].y == 1)
		return true;
	else
		return false;
}

void MoveRight()
{
	if (CrashWall() || CrashItself() || (CrashGate() && GATE_EXIST))
	{
		ProcessDead();
	}
	else
	{
		if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
		{
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x++;
	}
}

void MoveLeft()
{
	if (CrashWall() || CrashItself() || (CrashGate() && GATE_EXIST))
	{
		ProcessDead();
	}
	else
	{
		if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
		{
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x--;
	}
}

void MoveDown()
{
	if (CrashWall() || CrashItself() || (CrashGate() && GATE_EXIST))
	{
		ProcessDead();
	}
	else
	{
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y)
		{
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y++;
	}
}

void MoveUp()
{
	if (CrashWall() || CrashItself() || (CrashGate() && GATE_EXIST))
	{
		ProcessDead();
	}
	else
	{
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y)
		{
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y--;
	}
}

void ThreadFunc()
{
	while (true)
	{
		if (STATE == 1)
		{
			DeleteTail();
			switch (MOVING)
			{
			case 'A':
				CHAR_LOCK = 'D';
				MoveLeft();
				break;
			case 'D':
				CHAR_LOCK = 'A';
				MoveRight();
				break;
			case 'W':
				CHAR_LOCK = 'S';
				MoveUp();
				break;
			case 'S':
				CHAR_LOCK = 'W';
				MoveDown();
				break;
			}
			ProcessGate();
			if (win == 9) {
				system("cls");
				PrintWin();
			}
			else
				DrawSnake();
			Sleep(300 / SPEED);
		}
		else
		{
			bool Continue = ContinueGame();
			if (!Continue)
			{
				system("cls");
				exit(0);
			}
		}
	}
}

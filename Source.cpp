#include "Header.h"

int main()
{
	InitialGame();
	InitializeHighLength();
	PlaySound(L".\\menu.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	MENU choose = menugame();

	while (true)
	{
		if (choose.selecting == 13)
		{
			if (choose.choice == highlength || choose.choice == exitgame)
			{
				STATE = 0;
				system("cls");
				break;
				//Tao bi ngu nen tao phai tham khao code cua do an cu
			}
			system("cls");
			STATE = 1;
			break;
		}
	}
	if (STATE)
	{
		StartGame();
		thread t1(ThreadFunc);
		HANDLE handle_t1 = t1.native_handle();

		while (true)
		{
			temp = toupper(_getch());
			if (STATE == 1)
			{
				if (win == 9)
				{
					PauseGame(handle_t1);
					ExitGame(t1);
					return 0;
				}
				else if (temp == 'P')
				{
					PauseGame(handle_t1);
				}
				else if (temp == 'L')
				{
					PauseGame(handle_t1);
					SaveData();
					ExitGame(t1);
					return 0;
				}
				else if (temp == 'T')
				{
					PauseGame(handle_t1);
					LoadData();
					ResumeThread(handle_t1);
				}
				else if (temp == 27)
				{
					ExitGame(t1);
					return 0;
				}
				else
				{
					if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S'))
					{
						MOVING = temp;
						ResumeThread(handle_t1);
					}
				}
			}
		}
	}
	return 0;
}
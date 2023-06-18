#include "MainHeader.h"
#define dino_Y 17 //공룡의 시작 위치 Y값
#define tree_Y 25 //나무의 시작 위치 Y값
#define tree_X 45 //나무의 시작 위치 X값
#define space 32 //아스키코드값 space를 활용하기 위한 값
//커서의 위치를 특정 위치 즉 (x, y)로 이동시키기 위하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;   //x, y를 가지고 있는 구조체, 즉 커서의 위치를 저장하는 구조체
	Pos.X = 2 * x; //x만 2를 곱한 이유는 공룡이 걸어가는 속도를 내기 위해서
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//원하는 좌표로 커서 이동하기 위한 함수, *windows.h헤더가 필요함
}
// 키보드를 키를 누르면 아스키 코드 값을 출력하도록 만듬
//키보드의 입력을 받고, 입력된 키의 값(아스키코드 값)을 반환하는 함수 - 나중에 space바의 입력을 받고 출력하기 위함.
int GetKeyDown()
{      //이때 필요한 헤더 파일은 conio.h임. _getch()사용을위함.
	if (_kbhit() != 0)  //  _kbhit()함수는 키보드를 누르면 1을 반환, 누르지 않으면 0을 반환.
	{
		return _getch(); // _getch()함수는 키보드 입력을 받으면 아스키 코드 값을 반환함. 
	}                    // 키보드를 키를 누르면 아스키 코드 값을 출력하도록 만듬  
	return 0;
}

//공룡을 그리는 함수
void DrawDino(int dinoY) //헷갈리게 하지 않기 위해 dinoY로 선언
{
	GotoXY(0, dinoY); //공룡의 시작 위치는 (0, dinoY)가 되어버림.
	static bool legFlag = true; //static은 정적변수를 만들때 쓰임, 끝날때까지 고정 bool을 통해 true(1) false(0)을 써서
								//함수를 활용하여 두 출력함수가 왔다갔다 하는데, 움직이는 것처럼 보이게 도움.
	printf("          ▲▲▲▲ \n");
	printf("         ■■■"); textcolor(4); printf("●"); textcolor(7); printf("■\n");
	printf("        ■■■■■▶\n");
	printf("◀■      ■■      \n");
	printf("◀■     ■■■■■  \n");
	printf("  ■■   ■■■     \n");
	printf("   ■  ■■■■■■ \n");
	printf("   ■■■■■■■   \n");     //■◀▶▲▼◀● 기호들을 활용하여 공룡을 그림
	printf("    ■■■■■    \n");
	printf("      ■■■■    \n");
	printf("       ■■■     \n");
	if (legFlag) //공룡의 다리가 움직이게 하도록 만드는 함수
	{
		printf("     ■    ■■    \n");
		printf("     ■■          ");
		legFlag = false;  //왼발을 한 번 출력하고 false를 반환함으로써 오른쪽 다리가 출력되는데
	}
	else
	{
		printf("     ■■  ■     \n");
		printf("           ■■   ");
		legFlag = true;   //false의 출력으로 else문으로 돌아와 오른쪽 다리가 출력되고, 다시 true를 반환하여
						  //왼쪽 다리의 출력으로 걷는 것처럼 보인다.
	}
}

//나무를 그리는 함수
void DrawTree(int treeX)
{
	GotoXY(treeX, tree_Y); textcolor(2);//커서의 위치를 특정 위치 즉 나무의(x, y)로 이동시키기 위하는 함수
	printf("$$$$");
	GotoXY(treeX, tree_Y + 1);  textcolor(13);//나무를 그리기 위해 좌표를 1개씩 내림
	printf(" $$ ");
	GotoXY(treeX, tree_Y + 2);
	printf(" $$ ");
	GotoXY(treeX, tree_Y + 3);
	printf(" $$ ");
	GotoXY(treeX, tree_Y + 4);
	printf(" $$ "); textcolor(7);
}

//공룡과 나무가 충돌 했을때 게임오버 출력함
int DrawGameOver(const int score)
{
	int _select;
	system("cls"); //화면 초기화
	int x = 18;
	int y = 8;
	GotoXY(x, y);   //(18,8)좌표에 출력
	printf("===========================");
	GotoXY(x, y + 1);
	printf("======G A M E O V E R======");
	GotoXY(x, y + 2);
	printf("=====1================0====");
	GotoXY(x, y + 5);
	printf("SCORE : %d", score); //게임오버 후의 점수

	printf("\n\n\n\n\n\n\n\n\n");
	fflush(stdin);
	cin >> _select;
	cout << "0입력시 메인 화면으로";
	if (_select == 0) { return 0; }
}

// 충돌했으면 true, 아니면 false 출력
bool isCollision(const int treeX, const int dinoY) //const 키워드는 값을 상수로 선언할 수 있도록 도와주는 키워드 이다
{                                                  //즉, 값을 변경할 수 없도록 하기 위해 사용
	//트리의 X가 공룡의 몸체쪽에 있을때,
	//공룡의 높이가 충분하지 않다면 충돌로 처리
	GotoXY(0, 0);
	printf("treeX : %d, dinoY : %d", treeX, dinoY); //현재 트리의 위치와 공룡의 높이의 값이 출력 
	if (treeX >= 4 && treeX <= 8 &&                 //점프 할 때 좌표를 정확하게 보기 위함
		dinoY > 8) //트리의 X좌표가 4~8사이 공룡의 높이가 8이상일때 충돌, true값 출력
	{
		return true;
	}
	return false;
}
int Dino()
{
	int x = 30, y = 6; CursorView();
	system("cls"); gotoxy(x , y); cout << "3"; gotoxy(x, y); Sleep(1000); cout << "2"; gotoxy(x, y); Sleep(1000); cout << "1"; Sleep(1000);
	system("mode con:cols=100 lines=30");  //콘솔 창의 크기
	while (true)        //게임 루프
	{

		//게임 시작시 초기화
		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3; //점프 높이의 값

		int dinoY = dino_Y; // 높이 Y: 17
		int treeX = tree_X; // X: 45
		GotoXY(treeX, dinoY);
		int score = 0;
		clock_t start, curr;    //점수 변수 초기화 (clock_t는  프로그램의 실행 시작으로부터 경과된 시간을 측정)
		start = clock();        //시작시간 초기화

		while (true)    //게임에 대한 루프
		{
			//충돌체크 트리의 x값과 공룡의 y값으로 충돌 확인
			if (isCollision(treeX, dinoY))
				break;

			//스페이스 바 키가 눌렸고, 바닥에 닿아있을때 점프(점프 중간에 점프 X)
			//이때 GetAsyncKeyState 함수를 사용해 다중키를 입력받고 사용할 수 있음
			//window.h를 사용함. 
			//**(원래는 GetKeyDown()함수를 통해 아스키코드 값을 반환하도록 하려고 했으나
			//_getch()는 키 입력 하나만 받을 수 있기에 여러 키를 입력받고싶어 GetAsyncKeyState를 사용함)
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 && isBottom)
			{
				isJumping = true; //점프중인 상황
				isBottom = false; //바닥에 닿아있을 때
			}
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) //ESC키 입력시 강제종료
			{
				assert(0); // 강제종료
						   // assert.h 헤더파일을 사용함.
			}
			if (GetAsyncKeyState(VK_NEXT) & 0x8000) //PAGE DOWN키를 누르면 잠시 멈춤
			{
				system("pause");
			}

			//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가. (Y축이 아래로 가는게 +이기때문에 
			//Y의 값이 감소해야 점프하는 것처럼 출력
			if (isJumping) //점프했다면,
			{
				dinoY -= gravity; //gravity의 값(공룡의 Y값)이 감소
			}
			else
			{
				dinoY += gravity; //점프 후에 내려오는 중이므로 gravity의 값이 증가
			}

			//Y가 계속해서 증가하는걸 막기위해 바닥을 지정함
			if (dinoY >= dino_Y) //
			{
				dinoY = dino_Y;
				isBottom = true;
			}

			//나무가 왼쪽으로 (x가 음수를 향해) 가도록하고
			//나무의 위치가 왼쪽 끝으로가면(X가 음수) 다시 오른쪽 끝으로 소환.
			treeX -= 2;  //->treeX = treeX - 2
			if (treeX <= 0)
			{
				treeX = tree_X;
			}

			//점프의 맨위를 찍으면 점프가 끝난 상황.
			if (dinoY <= 3)
			{
				isJumping = false;
			}

			DrawDino(dinoY);        //공룡 그림 출력 함수
			DrawTree(treeX);        //나무 그림 출력 함수

			curr = clock();            //현재시간 받기
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1초가 넘었을때, CLOCKS_PER_SEC는 초당 clock 의 수를 나타낸 매크로임
			{
				score += 10;    //스코어 증가
				start = clock();    //시작시간 초기화
			}//점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 점수를 더해줌
			Sleep(60); //속도를 낮춤으로써 플레이어가 눈으로 봤을때 보기 쉬운 속도로 게임을 할 수 있게 만들어줌.
			system("cls");    //clear

			GotoXY(22, 0);    //커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
			printf("Score : %d ", score);    //점수 출력해줌.

		}


		// 게임 오버와 스코어를 출력
		if (DrawGameOver(score) == 0) { break; }

		break;
		return 0;
	}
	
	return (0);
}
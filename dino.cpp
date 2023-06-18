#include "MainHeader.h"
#define dino_Y 17 //������ ���� ��ġ Y��
#define tree_Y 25 //������ ���� ��ġ Y��
#define tree_X 45 //������ ���� ��ġ X��
#define space 32 //�ƽ�Ű�ڵ尪 space�� Ȱ���ϱ� ���� ��
//Ŀ���� ��ġ�� Ư�� ��ġ �� (x, y)�� �̵���Ű�� ���ϴ� �Լ�
void GotoXY(int x, int y)
{
	COORD Pos;   //x, y�� ������ �ִ� ����ü, �� Ŀ���� ��ġ�� �����ϴ� ����ü
	Pos.X = 2 * x; //x�� 2�� ���� ������ ������ �ɾ�� �ӵ��� ���� ���ؼ�
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//���ϴ� ��ǥ�� Ŀ�� �̵��ϱ� ���� �Լ�, *windows.h����� �ʿ���
}
// Ű���带 Ű�� ������ �ƽ�Ű �ڵ� ���� ����ϵ��� ����
//Ű������ �Է��� �ް�, �Էµ� Ű�� ��(�ƽ�Ű�ڵ� ��)�� ��ȯ�ϴ� �Լ� - ���߿� space���� �Է��� �ް� ����ϱ� ����.
int GetKeyDown()
{      //�̶� �ʿ��� ��� ������ conio.h��. _getch()���������.
	if (_kbhit() != 0)  //  _kbhit()�Լ��� Ű���带 ������ 1�� ��ȯ, ������ ������ 0�� ��ȯ.
	{
		return _getch(); // _getch()�Լ��� Ű���� �Է��� ������ �ƽ�Ű �ڵ� ���� ��ȯ��. 
	}                    // Ű���带 Ű�� ������ �ƽ�Ű �ڵ� ���� ����ϵ��� ����  
	return 0;
}

//������ �׸��� �Լ�
void DrawDino(int dinoY) //�򰥸��� ���� �ʱ� ���� dinoY�� ����
{
	GotoXY(0, dinoY); //������ ���� ��ġ�� (0, dinoY)�� �Ǿ����.
	static bool legFlag = true; //static�� ���������� ���鶧 ����, ���������� ���� bool�� ���� true(1) false(0)�� �Ἥ
								//�Լ��� Ȱ���Ͽ� �� ����Լ��� �Դٰ��� �ϴµ�, �����̴� ��ó�� ���̰� ����.
	printf("          ����� \n");
	printf("         ����"); textcolor(4); printf("��"); textcolor(7); printf("��\n");
	printf("        �����ᢺ\n");
	printf("����      ���      \n");
	printf("����     ������  \n");
	printf("  ���   ����     \n");
	printf("   ��  ������� \n");
	printf("   ��������   \n");     //�ᢸ����墸�� ��ȣ���� Ȱ���Ͽ� ������ �׸�
	printf("    ������    \n");
	printf("      �����    \n");
	printf("       ����     \n");
	if (legFlag) //������ �ٸ��� �����̰� �ϵ��� ����� �Լ�
	{
		printf("     ��    ���    \n");
		printf("     ���          ");
		legFlag = false;  //�޹��� �� �� ����ϰ� false�� ��ȯ�����ν� ������ �ٸ��� ��µǴµ�
	}
	else
	{
		printf("     ���  ��     \n");
		printf("           ���   ");
		legFlag = true;   //false�� ������� else������ ���ƿ� ������ �ٸ��� ��µǰ�, �ٽ� true�� ��ȯ�Ͽ�
						  //���� �ٸ��� ������� �ȴ� ��ó�� ���δ�.
	}
}

//������ �׸��� �Լ�
void DrawTree(int treeX)
{
	GotoXY(treeX, tree_Y); textcolor(2);//Ŀ���� ��ġ�� Ư�� ��ġ �� ������(x, y)�� �̵���Ű�� ���ϴ� �Լ�
	printf("$$$$");
	GotoXY(treeX, tree_Y + 1);  textcolor(13);//������ �׸��� ���� ��ǥ�� 1���� ����
	printf(" $$ ");
	GotoXY(treeX, tree_Y + 2);
	printf(" $$ ");
	GotoXY(treeX, tree_Y + 3);
	printf(" $$ ");
	GotoXY(treeX, tree_Y + 4);
	printf(" $$ "); textcolor(7);
}

//����� ������ �浹 ������ ���ӿ��� �����
int DrawGameOver(const int score)
{
	int _select;
	system("cls"); //ȭ�� �ʱ�ȭ
	int x = 18;
	int y = 8;
	GotoXY(x, y);   //(18,8)��ǥ�� ���
	printf("===========================");
	GotoXY(x, y + 1);
	printf("======G A M E O V E R======");
	GotoXY(x, y + 2);
	printf("=====1================0====");
	GotoXY(x, y + 5);
	printf("SCORE : %d", score); //���ӿ��� ���� ����

	printf("\n\n\n\n\n\n\n\n\n");
	fflush(stdin);
	cin >> _select;
	cout << "0�Է½� ���� ȭ������";
	if (_select == 0) { return 0; }
}

// �浹������ true, �ƴϸ� false ���
bool isCollision(const int treeX, const int dinoY) //const Ű����� ���� ����� ������ �� �ֵ��� �����ִ� Ű���� �̴�
{                                                  //��, ���� ������ �� ������ �ϱ� ���� ���
	//Ʈ���� X�� ������ ��ü�ʿ� ������,
	//������ ���̰� ������� �ʴٸ� �浹�� ó��
	GotoXY(0, 0);
	printf("treeX : %d, dinoY : %d", treeX, dinoY); //���� Ʈ���� ��ġ�� ������ ������ ���� ��� 
	if (treeX >= 4 && treeX <= 8 &&                 //���� �� �� ��ǥ�� ��Ȯ�ϰ� ���� ����
		dinoY > 8) //Ʈ���� X��ǥ�� 4~8���� ������ ���̰� 8�̻��϶� �浹, true�� ���
	{
		return true;
	}
	return false;
}
int Dino()
{
	int x = 30, y = 6; CursorView();
	system("cls"); gotoxy(x , y); cout << "3"; gotoxy(x, y); Sleep(1000); cout << "2"; gotoxy(x, y); Sleep(1000); cout << "1"; Sleep(1000);
	system("mode con:cols=100 lines=30");  //�ܼ� â�� ũ��
	while (true)        //���� ����
	{

		//���� ���۽� �ʱ�ȭ
		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3; //���� ������ ��

		int dinoY = dino_Y; // ���� Y: 17
		int treeX = tree_X; // X: 45
		GotoXY(treeX, dinoY);
		int score = 0;
		clock_t start, curr;    //���� ���� �ʱ�ȭ (clock_t��  ���α׷��� ���� �������κ��� ����� �ð��� ����)
		start = clock();        //���۽ð� �ʱ�ȭ

		while (true)    //���ӿ� ���� ����
		{
			//�浹üũ Ʈ���� x���� ������ y������ �浹 Ȯ��
			if (isCollision(treeX, dinoY))
				break;

			//�����̽� �� Ű�� ���Ȱ�, �ٴڿ� ��������� ����(���� �߰��� ���� X)
			//�̶� GetAsyncKeyState �Լ��� ����� ����Ű�� �Է¹ް� ����� �� ����
			//window.h�� �����. 
			//**(������ GetKeyDown()�Լ��� ���� �ƽ�Ű�ڵ� ���� ��ȯ�ϵ��� �Ϸ��� ������
			//_getch()�� Ű �Է� �ϳ��� ���� �� �ֱ⿡ ���� Ű�� �Է¹ް�;� GetAsyncKeyState�� �����)
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 && isBottom)
			{
				isJumping = true; //�������� ��Ȳ
				isBottom = false; //�ٴڿ� ������� ��
			}
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) //ESCŰ �Է½� ��������
			{
				assert(0); // ��������
						   // assert.h ��������� �����.
			}
			if (GetAsyncKeyState(VK_NEXT) & 0x8000) //PAGE DOWNŰ�� ������ ��� ����
			{
				system("pause");
			}

			//�������̶�� Y�� ����, ������ �������� Y�� ����. (Y���� �Ʒ��� ���°� +�̱⶧���� 
			//Y�� ���� �����ؾ� �����ϴ� ��ó�� ���
			if (isJumping) //�����ߴٸ�,
			{
				dinoY -= gravity; //gravity�� ��(������ Y��)�� ����
			}
			else
			{
				dinoY += gravity; //���� �Ŀ� �������� ���̹Ƿ� gravity�� ���� ����
			}

			//Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ������
			if (dinoY >= dino_Y) //
			{
				dinoY = dino_Y;
				isBottom = true;
			}

			//������ �������� (x�� ������ ����) �������ϰ�
			//������ ��ġ�� ���� �����ΰ���(X�� ����) �ٽ� ������ ������ ��ȯ.
			treeX -= 2;  //->treeX = treeX - 2
			if (treeX <= 0)
			{
				treeX = tree_X;
			}

			//������ ������ ������ ������ ���� ��Ȳ.
			if (dinoY <= 3)
			{
				isJumping = false;
			}

			DrawDino(dinoY);        //���� �׸� ��� �Լ�
			DrawTree(treeX);        //���� �׸� ��� �Լ�

			curr = clock();            //����ð� �ޱ�
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1�ʰ� �Ѿ�����, CLOCKS_PER_SEC�� �ʴ� clock �� ���� ��Ÿ�� ��ũ����
			{
				score += 10;    //���ھ� ����
				start = clock();    //���۽ð� �ʱ�ȭ
			}//��������� 1�ʸ��� ���ִ°��� �ƴ϶� �׻� ������ָ鼭, 1�ʰ� �������� ������ ������
			Sleep(60); //�ӵ��� �������ν� �÷��̾ ������ ������ ���� ���� �ӵ��� ������ �� �� �ְ� �������.
			system("cls");    //clear

			GotoXY(22, 0);    //Ŀ���� ��� �������� �ű��. �ܼ�â�� cols=100�̴ϱ� 2*x�̹Ƿ� 22���� �־���
			printf("Score : %d ", score);    //���� �������.

		}


		// ���� ������ ���ھ ���
		if (DrawGameOver(score) == 0) { break; }

		break;
		return 0;
	}
	
	return (0);
}
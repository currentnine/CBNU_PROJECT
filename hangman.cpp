#include "MainHeader.h"
int life = 9; //��� ����� ����
int screen() {
	system("mode con cols=59 lines=15");
	//��� ���� ���� ��ũ�� ��� 
	cout << "������������������������������������������������������������������������\n";
	cout << "��                                  ��\n";
	cout << "��                                  ��\n";
	cout << "��                                  ��\n";
	cout << "��           Hangman Game           ��\n";
	cout << "��                                  ��\n";
	cout << "��                                  ��\n";
	cout << "��                                  ��\n";
	cout << "������������������������������������������������������������������������\n";
	cout << "      PRESS ANY KEY TO START";
	_getch(); // �ƹ� Ű�� �Է¹ް�
	system("cls");//ȭ�� �ʱ�ȭ�� ��Ű�� ��� ������ ����
	return 0;
}
void hangman() {
	system("cls");
	screen(); //main screen������Ͽ� �ִ� ���ν�ũ���� ����ϴ� �Լ�
	srand(unsigned(time(NULL))); //���� �Լ� - list�ȿ� �ִ� �ܾ�� �� �������� ���� ����
	char ch;
	string list[] = { "apple","avocado","banana","blueberry",
"pear","cherry","cranberry","coconut","grape","strawberry" }; //list �ȿ� ���� �ܾ��
	int r = rand() % 10; //10���� ���� �ܾ ������ ����
	string str = list[r]; //list�ȿ� �ִ� ���� �ܾ� �� �����Լ��� ���� str�� ����
	string word(str.length(), '_'); //���Ƿ� ������ �ܾ��� ���̸�ŭ '_'�� ���
	while (true) {
		int flag = 0; //flag ���� 0���� �ʱ�ȭ
		switch (life) {// ����� life ���϶� ����� ����� ����ϱ� ����
			// ����� ����� ���� �Էµ� �ܾ �����.
		case 9:
			cout << "   ������������\n";
			cout << "   ��   ��\n";
			cout << "  ������   ��\n";
			cout << "   ��    ��\n";
			cout << "  ������   ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;
		case 8:
			system("cls");
			cout << "   ������������\n";
			cout << "   ��   ��\n";
			cout << "  ������   ��\n";
			cout << "   ��    ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;

		case 7:
			system("cls");
			cout << "   ������������\n";
			cout << "   ��   ��\n";
			cout << "  ������   ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;
		case 6:
			system("cls");
			cout << "   ������������\n";
			cout << "   ��   ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;
		case 5:
			system("cls");
			cout << "   ������������\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;
		case 4:
			system("cls");
			cout << "    ����������\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;
		case 3:
			system("cls");
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;
		case 2:
			system("cls");
			cout << "          \n";
			cout << "         \n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;
		case 1:
			system("cls");
			cout << "          \n";
			cout << "         \n";
			cout << "         \n";
			cout << "         \n";
			cout << "        ��\n";
			cout << "        ��\n";
			cout << word << endl << endl;
			break;
		case 0:
			break;
		}

		cout << "���ڸ� �Է� : ";
		cin >> ch;      //����� �ܾ ���߱� ���� ���� �Է�
		for (int i = 0; i < str.length(); i++) { //str.length() str�� ���ڿ� ���̸� ������.
			if (ch == str[i]) { // string str = list[r]; �� ���� list�� �ִ� ������ �ܾ ���õǰ�
				// �� �ܾ �´��� Ȯ���ϱ� ���� 
				word[i] = ch;   // �ܾ ��ġ�� ��� word���ڿ��� �ܾ ä����.
				flag++;         //���ڰ� ��ġ�ϸ� ȭ�� �ʱ�ȭ, ���� ���� ���� üũ ���� flag�� 1 ��½�Ŵ
			}
		}

		if (flag != 0) { //�Է��� ���ڰ� �´ٸ� ȭ���� �ʱ�ȭ
			system("cls");
		}
		else { life--; }//�Է��� ���ڰ� Ʋ���� ��� -1

		if (life == 0) { //����� 0���� GAME OVER
			system("cls");
			cout << "\n\n=======================================";
			cout << "\n\n=============< GAME OVER >=============";
			cout << "\n\n=======================================";
			break;
		}
		if (str == word) { //�Է��� �ܾ�� ���Ƿ� ����� �ܾ ��ġ�ϸ� ���� �� ���Ƿ� ����� �ܾ� ���
			cout << "\n\n=============COMPLETE!!================";
			cout << "\n\n=======================================";
			cout << "\n\n===========< ANSWER:" << str << ">==========";
			cout << "\n\n=======================================";
			Sleep(2000);
			break;
		}
	}
}
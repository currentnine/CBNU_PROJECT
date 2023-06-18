#include "MainHeader.h"
int life = 9; //행멘 목숨의 개수
int screen() {
	system("mode con cols=59 lines=15");
	//행맨 시작 메인 스크린 출력 
	cout << "┌──────────────────────────────────┐\n";
	cout << "│                                  │\n";
	cout << "│                                  │\n";
	cout << "│                                  │\n";
	cout << "│           Hangman Game           │\n";
	cout << "│                                  │\n";
	cout << "│                                  │\n";
	cout << "│                                  │\n";
	cout << "└──────────────────────────────────┘\n";
	cout << "      PRESS ANY KEY TO START";
	_getch(); // 아무 키를 입력받고
	system("cls");//화면 초기화를 시키고 행맨 게임을 시작
	return 0;
}
void hangman() {
	system("cls");
	screen(); //main screen헤더파일에 있는 메인스크린을 출력하는 함수
	srand(unsigned(time(NULL))); //랜덤 함수 - list안에 있는 단어들 중 랜덤으로 고르기 위함
	char ch;
	string list[] = { "apple","avocado","banana","blueberry",
"pear","cherry","cranberry","coconut","grape","strawberry" }; //list 안에 넣을 단어들
	int r = rand() % 10; //10개의 랜덤 단어를 돌리기 위함
	string str = list[r]; //list안에 있는 여러 단어 중 랜덤함수를 통해 str에 저장
	string word(str.length(), '_'); //임의로 지정된 단어의 길이만큼 '_'를 출력
	while (true) {
		int flag = 0; //flag 값을 0으로 초기화
		switch (life) {// 목숨이 life 개일때 행맨의 모습을 출력하기 위함
			// 행맨의 모습과 현재 입력된 단어를 출력함.
		case 9:
			cout << "   ┌────┐\n";
			cout << "   ●   │\n";
			cout << "  ┌┼┐   │\n";
			cout << "   │    │\n";
			cout << "  ┌┴┐   │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;
		case 8:
			system("cls");
			cout << "   ┌────┐\n";
			cout << "   ●   │\n";
			cout << "  ┌┼┐   │\n";
			cout << "   │    │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;

		case 7:
			system("cls");
			cout << "   ┌────┐\n";
			cout << "   ●   │\n";
			cout << "  ┌┼┐   │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;
		case 6:
			system("cls");
			cout << "   ┌────┐\n";
			cout << "   ●   │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;
		case 5:
			system("cls");
			cout << "   ┌────┐\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;
		case 4:
			system("cls");
			cout << "    ────┐\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;
		case 3:
			system("cls");
			cout << "        ┐\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;
		case 2:
			system("cls");
			cout << "          \n";
			cout << "         \n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;
		case 1:
			system("cls");
			cout << "          \n";
			cout << "         \n";
			cout << "         \n";
			cout << "         \n";
			cout << "        │\n";
			cout << "        │\n";
			cout << word << endl << endl;
			break;
		case 0:
			break;
		}

		cout << "문자를 입력 : ";
		cin >> ch;      //행맨의 단어를 맞추기 위한 문자 입력
		for (int i = 0; i < str.length(); i++) { //str.length() str의 문자열 길이를 가져옴.
			if (ch == str[i]) { // string str = list[r]; 를 통해 list에 있는 임의의 단어가 선택되고
				// 그 단어가 맞는지 확인하기 위함 
				word[i] = ch;   // 단어가 일치할 경우 word문자열의 단어를 채워줌.
				flag++;         //문자가 일치하면 화면 초기화, 문자 맞춘 것을 체크 위해 flag를 1 상승시킴
			}
		}

		if (flag != 0) { //입력한 문자가 맞다면 화면을 초기화
			system("cls");
		}
		else { life--; }//입력한 문자가 틀리면 목숨 -1

		if (life == 0) { //목숨이 0개면 GAME OVER
			system("cls");
			cout << "\n\n=======================================";
			cout << "\n\n=============< GAME OVER >=============";
			cout << "\n\n=======================================";
			break;
		}
		if (str == word) { //입력한 단어와 임의로 저장된 단어가 일치하면 성공 후 임의로 저장된 단어 출력
			cout << "\n\n=============COMPLETE!!================";
			cout << "\n\n=======================================";
			cout << "\n\n===========< ANSWER:" << str << ">==========";
			cout << "\n\n=======================================";
			Sleep(2000);
			break;
		}
	}
}
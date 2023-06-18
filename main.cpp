#include "MainHeader.h"
#define UP 72
#define DOWN 80 //키보드 방향키의 아스키코드값을 정의해둔것입니다.
#define ENTER 13     //이런식으로 정의해두면 편하게 사용할 수 있습니다.


#pragma comment(lib,"winmm.lib")
int main() {
	int select = 0, x = 0, y = 0;
	while (true) { jump:
		system("mode con cols=59 lines=15"); system("cls"); // 게임의 메인화면 콘솔 창의 크기 조절.
		//gotoxy(15, 2);
		cout << "┎───────────────────────────────────────────────────────┒" << endl; textcolor(6);
		cout << "┃     #####         ##           #      #      ######## ┃" << endl; textcolor(14);
		cout << "┃   ##             #  #         ###    ###     #        ┃" << endl; textcolor(2);
		cout << "┃   #  #####      ######       #  #   #   #    ######## ┃" << endl; textcolor(10);
		cout << "┃   ##      #    #      #     #    # #     #   #        ┃" << endl; textcolor(1);
		cout << "┃    #######    #        #   #      #       #  ######## ┃" << endl; textcolor(9);
		cout << "┖───────────────────────────────────────────────────────┚" << endl; textcolor(15);
		cout << "           "; system("pause"); system("cls"); 
		cout << "┎───────────────────────────────────────────────────────┒" << endl; textcolor(6);
		cout << "┃     #####         ##           #      #      ######## ┃" << endl; textcolor(14);
		cout << "┃   ##             #  #         ###    ###     #        ┃" << endl; textcolor(2);
		cout << "┃   #  #####      ######       #  #   #   #    ######## ┃" << endl; textcolor(10);
		cout << "┃   ##      #    #      #     #    # #     #   #        ┃" << endl; textcolor(1);
		cout << "┃    #######    #        #   #      #       #  ######## ┃" << endl; textcolor(9);
		cout << "┖───────────────────────────────────────────────────────┚" << endl; textcolor(15);
		gotoxy(20, 7); cout << "   Maze(미로 찾기)\n"; gotoxy(20, 8); cout << "   HangMan\n"; gotoxy(20, 9); cout << "   Dino Jump!\n"; gotoxy(20, 10); cout << "   exit\n"; 
		x = 20; y = 7; gotoxy(20, 7); printf(">");
		while (true) {
	
			select = _getch();// 키보드 방향키를 받아들입니다.
			switch (select) {
			case UP: gotoxy(x, y); printf("  "); y -= 1;
				if (y >= 7) {
					gotoxy(x, y); printf(">");
					break;
				}
				else {
					y += 1;//막힌길이면 좌표를 다시 되돌린후에
					gotoxy(x, y);
					printf(">");//다시 출력해줍니다.
					break;
				}
			case DOWN: gotoxy(x, y); printf("  "); y += 1;
				if (y <= 10) {
					gotoxy(x, y); printf(">");
					break;
				}
				else {
					y -= 1;//막힌길이면 좌표를 다시 되돌린후에
					gotoxy(x, y);
					printf(">");//다시 출력해줍니다.
					break;
				}
			case ENTER: 
				if (y == 7) {
					Miro(); goto jump; break;
				}
				else if (y == 8) {
					hangman(); goto jump; break;
				}
				else if (y == 9) {
					if (Dino() == 0) goto jump;
				}
				else {
					exit(0);
				}
			}
		
	}
return 0;
}

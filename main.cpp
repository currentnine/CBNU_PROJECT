#include "MainHeader.h"
#define UP 72
#define DOWN 80 //Ű���� ����Ű�� �ƽ�Ű�ڵ尪�� �����صа��Դϴ�.
#define ENTER 13     //�̷������� �����صθ� ���ϰ� ����� �� �ֽ��ϴ�.


#pragma comment(lib,"winmm.lib")
int main() {
	int select = 0, x = 0, y = 0;
	while (true) { jump:
		system("mode con cols=59 lines=15"); system("cls"); // ������ ����ȭ�� �ܼ� â�� ũ�� ����.
		//gotoxy(15, 2);
		cout << "�Ǧ���������������������������������������������������������������������������������������������������������������" << endl; textcolor(6);
		cout << "��     #####         ##           #      #      ######## ��" << endl; textcolor(14);
		cout << "��   ##             #  #         ###    ###     #        ��" << endl; textcolor(2);
		cout << "��   #  #####      ######       #  #   #   #    ######## ��" << endl; textcolor(10);
		cout << "��   ##      #    #      #     #    # #     #   #        ��" << endl; textcolor(1);
		cout << "��    #######    #        #   #      #       #  ######## ��" << endl; textcolor(9);
		cout << "�Ŧ���������������������������������������������������������������������������������������������������������������" << endl; textcolor(15);
		cout << "           "; system("pause"); system("cls"); 
		cout << "�Ǧ���������������������������������������������������������������������������������������������������������������" << endl; textcolor(6);
		cout << "��     #####         ##           #      #      ######## ��" << endl; textcolor(14);
		cout << "��   ##             #  #         ###    ###     #        ��" << endl; textcolor(2);
		cout << "��   #  #####      ######       #  #   #   #    ######## ��" << endl; textcolor(10);
		cout << "��   ##      #    #      #     #    # #     #   #        ��" << endl; textcolor(1);
		cout << "��    #######    #        #   #      #       #  ######## ��" << endl; textcolor(9);
		cout << "�Ŧ���������������������������������������������������������������������������������������������������������������" << endl; textcolor(15);
		gotoxy(20, 7); cout << "   Maze(�̷� ã��)\n"; gotoxy(20, 8); cout << "   HangMan\n"; gotoxy(20, 9); cout << "   Dino Jump!\n"; gotoxy(20, 10); cout << "   exit\n"; 
		x = 20; y = 7; gotoxy(20, 7); printf(">");
		while (true) {
	
			select = _getch();// Ű���� ����Ű�� �޾Ƶ��Դϴ�.
			switch (select) {
			case UP: gotoxy(x, y); printf("  "); y -= 1;
				if (y >= 7) {
					gotoxy(x, y); printf(">");
					break;
				}
				else {
					y += 1;//�������̸� ��ǥ�� �ٽ� �ǵ����Ŀ�
					gotoxy(x, y);
					printf(">");//�ٽ� ������ݴϴ�.
					break;
				}
			case DOWN: gotoxy(x, y); printf("  "); y += 1;
				if (y <= 10) {
					gotoxy(x, y); printf(">");
					break;
				}
				else {
					y -= 1;//�������̸� ��ǥ�� �ٽ� �ǵ����Ŀ�
					gotoxy(x, y);
					printf(">");//�ٽ� ������ݴϴ�.
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

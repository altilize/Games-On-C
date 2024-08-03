

/*



							==================================
							|				 |
							|	 MADE WITH LOVE BY	 |
							|	    MOSES JAGUAR 	 |
							|	   ( 622023006 )	 |
							|				 |
							==================================
							
							
							
							
							
*/





#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


void xy(int x, int y);
void test ();
void loading();
void printMenu(int posisi);
void printWave(int ampli, int wave);
void login ();
void awal();
void menu();
void reg ();
void color (int code);
void lupa();
int terdaftar (const char* id);
void TicTacToe();
void displayBoard();
int checkWin();
int checkDraw();
void playerMove();
int strategicMove(char mark);
void computerMove();
void resetBoard();
void eruption ();

struct PMN {
    char id[100];
    char password[100];
    int user;
} pemain;


struct wrg {
    char nama[50];
    float jarak;
    float velocity;
    char cara[20];
};


char board[10] = {'0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char player = 'O', computer = 'X';
int lastComputerMove = -1;





void menu ()
{
	int j;
    char ch;
    int input, posisi = 0; // posisi awal pada "GAME"
    
    color(10);
    printMenu(posisi);
    while (1) {

    	xy(1,50);
        ch = _getch();
        if (ch == 13) { // Enter key
            system("cls");
            if (posisi == 0)
            {
				TicTacToe();
			}
			else if (posisi == 1) 	// OSILOSCOPE
			{
				color(7);
				char input;
				int ampli=0,wave=0;
				while(1)
				{
			   	 system("cls");

				 printf("username : %s", pemain.id);
	 			 printf("\n\n========MINI OSILOSCOPE===========");
	 			 printf("\n1 : Input");
	 			 printf("\n2 : Output");	
				 printf("\n3 : Main Menu");
	 			 printf("\n==================================\n"); input = _getch(); fflush(stdin);
	
	 			if(input == '1')
	 			{
				system("cls");
				printf("Input Amplitudo\t\t: "); scanf("%d", &ampli);
				printf("Input Wavelength\t: "); scanf("%d", &wave);
				//	continue;
			    } 
				  else if(input == '2')
				{
	 		   	printWave(ampli,wave);
	 			}
	 			 else if(input == '3')
	 			{
	 			printMenu(posisi);
	 			break;
	 			}
		
			   }
				
			}
			else if(posisi == 2)
			{
				eruption();
				printMenu(posisi);
				continue;
				
			}
			else if (posisi == 3)
			{
			    color(7);
			    xy(1,1); printf("Are you sure you want to log out? (y/n)");
			    input = _getch();
			    if (input == 'y' || input == 'Y') {
			        system("cls");
			        awal(); // Kembali ke fungsi login untuk login ulang
			    } else {
			        printMenu(posisi); // Kembali ke menu jika tidak jadi logout
			        continue;
			    }
			}
			else if(posisi == 4)
			{
			    color(7);
			    xy(1,1); printf("Are you sure you want to exit? (y/n)");
			    input = _getch();
			    if (input == 'y' || input == 'Y') {
			        exit(0); // Kembali ke fungsi main untuk login ulang
			    } else if (input == 'n' || input == 'N') {
			        system("color A");
			        printMenu(posisi); // Kembali ke menu jika tidak jadi logout
			        continue;
			    }else
			    {
			    	continue;
				}
			}
        } else if (ch == -32) { // Arrow keys
            ch = _getch(); // get the specific arrow key code
            if (ch == 72) { // 72 Arrow Up
                posisi = (posisi == 0) ? 4 : posisi - 1;
            } else if (ch == 80) { // 80 Arrow Down
                posisi = (posisi == 4) ? 0 : posisi + 1;
            }
            printMenu(posisi);
        }
    }
//    color(7);
}
void printMenu(int posisi) {
	    const char* menu[] = {
        "   GAME    ",
        " OSILOSKOP ",
        " ERUPTION  ",
        "  LOG OUT  ",
        "   EXIT    "
    };
    system("cls");
    color(14);
    xy(48, 9); printf("Halo, %s!", strupr(pemain.id));
    xy(48, 10); printf("TR Dasprog 2024");
    for (int i = 0; i < 5; i++) {
        xy(50, 12 + i);
        if (i == posisi) {
        	color(14);
            xy(2, 9); printf("%d", i+1);
            xy(48, 12 + i);
            color(10);
            printf(">>%s<<", menu[i]);
        } else {
        	color(14);
            xy(50, 12 + i);
            printf("%s", menu[i]);
        }
    }
}



void eruption ()
{
	    FILE *input = fopen("warga.txt", "r");
    if (input == NULL) {
        printf("File tidak ditemukan!\n");
        exit (1);
    }

    // Jumlah dan spek warga
    int jumlah;
    fscanf(input, "%d", &jumlah);
    struct wrg warga[jumlah]; // Deklarasi array warga

    for (int i = 0; i < jumlah; i++) {
        fscanf(input, "%s %f %f %s", warga[i].nama, &warga[i].jarak, &warga[i].velocity, warga[i].cara);
    }

    // WEDHUS GEMBEL
    float safezone, velwedhus;
    fscanf(input, "%f %f", &safezone, &velwedhus);
    fclose(input);

    for (int i = 0; i < jumlah; i++) {
        if (warga[i].jarak >= safezone) {
            printf("%s aman\n", warga[i].nama);
            continue;
        }

        float waktu_warga = 0.0;
        if (strcmp(warga[i].cara, "kendaraan") == 0) {
            waktu_warga = (safezone - warga[i].jarak) / warga[i].velocity;
            
        } else if (strcmp(warga[i].cara, "lari") == 0) {
            float jarak_tempuh = safezone - warga[i].jarak;
            float waktu_lari = 2.0 / 60.0; // lama berlari dua menit dalam jam
            float vellari = waktu_lari * warga[i].velocity; // jarak yang ditempuh per dua menit
            while (jarak_tempuh > 0) {
                if (jarak_tempuh <= vellari) {
                    waktu_warga += jarak_tempuh / warga[i].velocity;
                    break;
                }
                jarak_tempuh -= vellari;
                waktu_warga += waktu_lari + (1.0 / 60.0); // tambahkan waktu istirahat 1 menit
            }
        }

        float waktuwedhus = (safezone) / velwedhus;

        if (waktu_warga < waktuwedhus) {
            printf("%s Selamat\n", warga[i].nama, waktu_warga);
        } else if (waktu_warga > waktuwedhus) {
            printf("%s Tewas\n", warga[i].nama, waktu_warga);
        }
    }
    
    FILE *output = fopen("evakuasi warga.txt", "w+");
        if (output == NULL) {
        printf("Tidak bisa membuat file evakuasi_warga.txt!\n");
        exit(1);
    }
    for (int i = 0; i < jumlah; i++) {
        if (warga[i].jarak >= safezone) {
            fprintf(output, "%s aman\n", warga[i].nama);
            continue;
        }

        float waktu_warga = 0.0;
        if (strcmp(warga[i].cara, "kendaraan") == 0) {
            waktu_warga = (safezone - warga[i].jarak) / warga[i].velocity;
        } else if (strcmp(warga[i].cara, "lari") == 0) {
            float jarak_tempuh = safezone - warga[i].jarak;
            float waktu_lari = 2.0 / 60.0; // lama berlari dua menit dalam jam
            float vellari = waktu_lari * warga[i].velocity; // jarak yang ditempuh per dua menit
            while (jarak_tempuh > 0) {
                if (jarak_tempuh <= vellari) {
                    waktu_warga += jarak_tempuh / warga[i].velocity;
                    break;
                }
                jarak_tempuh -= vellari;
                waktu_warga += waktu_lari + (1.0 / 60.0); // tambahkan waktu istirahat 1 menit
            }
        }

        float waktuwedhus = (safezone) / velwedhus;

        if (waktu_warga < waktuwedhus) {
            fprintf(output, "%s Selamat\n", warga[i].nama);
        } else {
            fprintf(output, "%s Tewas\n", warga[i].nama);
        }
    }

    fclose(output);
	getche();
}
    







void printBoard() {
	printf("USER : %s\n", strupr(pemain.id));
    printf("Posisi papan main berdasarkan angka:\n");
    printf(" 1 2 3\n");
    printf(" 4 5 6\n");
    printf(" 7 8 9\n\n");
    printf(" %c %c %c\n", board[1], board[2], board[3]);
    printf(" %c %c %c\n", board[4], board[5], board[6]);
    printf(" %c %c %c\n", board[7], board[8], board[9]);
}

// Mengecek apakah ada yang menang
int checkWin() {
    int winComb[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Baris
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Kolom
        {1, 5, 9}, {3, 5, 7}             // Diagonal
    };

    for (int i = 0; i < 8; i++) {
        if (board[winComb[i][0]] == board[winComb[i][1]] && board[winComb[i][1]] == board[winComb[i][2]] && board[winComb[i][0]] != ' ')
            return 1;
    }
    return 0;
}

// Mengecek apakah papan penuh (imbangan)
int checkDraw() {
    for (int i = 1; i < 10; i++) {
        if (board[i] != 'X' && board[i] != 'O')
            return 0;
    }
    return 1;
}

// Mengambil langkah pemain
void playerMove() {
    int move;
    printf("LETAKAN 'O' : ");
    scanf("%d", &move);	
    if (move < 1 || move > 9 || board[move] == 'X' || board[move] == 'O') {
        system("cls"); // Membersihkan layar jika input tidak valid
        printBoard();
        playerMove();
    } else {
        board[move] = player;
    }
}

// Fungsi untuk memeriksa dan melakukan langkah strategis
int strategicMove(char mark) {
    int winComb[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Baris
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Kolom
        {1, 5, 9}, {3, 5, 7}             // Diagonal
    };
    for (int i = 0; i < 8; i++) {
        int count = 0;
        int empty = -1;
        for (int j = 0; j < 3; j++) {
            if (board[winComb[i][j]] == mark) {
                count++;
            } else if (board[winComb[i][j]] != 'X' && board[winComb[i][j]] != 'O') {
                empty = winComb[i][j];
            }
        }
        if (count == 2 && empty != -1) {
            board[empty] = computer;
            lastComputerMove = empty;
            return 1;
        }
    }
    return 0;
}

// Fungsi untuk langkah komputer yang cerdas
void computerMove() {
    // Prioritas 1: Jika komputer hampir menang, menangkan
    if (strategicMove(computer)) {
        return;
    }
    // Prioritas 2: Jika pemain hampir menang, blokir
    if (strategicMove(player)) {
        return;
    }
    // Prioritas 3: Jika tengah kosong, isi tengah
    if (board[5] != 'X' && board[5] != 'O') {
        board[5] = computer;
        lastComputerMove = 5;
        return;
    }
    // Prioritas 4: Ambil sudut jika tersedia
    int corners[] = {1, 3, 7, 9};
    for (int i = 0; i < 4; i++) {
        if (board[corners[i]] != 'X' && board[corners[i]] != 'O') {
            board[corners[i]] = computer;
            lastComputerMove = corners[i];
            return;
        }
    }
    // Prioritas 5: Ambil langkah acak yang tersedia
    for (int i = 1; i < 10; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            board[i] = computer;
            lastComputerMove = i;
            return;
        }
    }
}
void resetBoard() {
    for (int i = 1; i < 10; i++) {
        board[i] = ' ';
    }
}

void TicTacToe (){
	int turn = 0;
	resetBoard();
    printBoard();
    printf("\nPLAYER 'O', COMPUTER 'X'.\n");

    while (1) {
        turn++;
        if (turn % 2 != 0) {
            playerMove();
        } else {
            computerMove();
            system("cls"); // Membersihkan layar setelah komputer mengambil langkah
            printBoard();
            printf("\nCOMPUTER: %d\n", lastComputerMove);
        }
        if (turn % 2 != 0) {
            system("cls"); // Membersihkan layar setelah pemain mengambil langkah
            printBoard();
        }
        if (checkWin()) {
            if (turn % 2 != 0) {
                printf("\nPLAYER 'O' menang!\n");
            } else {
                printf("\nCOMPUTER 'X' menang!\n");
            }
            getche();
            printMenu(0);
            break;
        }
        if (checkDraw()) {
            printf("\nPermainan imbang!\n"); getch();
            printMenu(0);
            break;
    
        }
    }

   
}







void color(int code)
{
	    // Mendapatkan handle ke output console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Mengatur warna teks
    SetConsoleTextAttribute(hConsole, code);
	
}

void lupa() {
    char idtemp[50];
    char line[100];
    int found = 0;

    // Bersihkan layar
    system("cls");
	color(7);
    // Minta user memasukkan ID
    xy(48,12);printf("Masukan ID Anda\t: ");
    scanf("%s", idtemp);

    // Buka file untuk membaca
    FILE* file = fopen("pemain.txt", "r");
    if (file == NULL) {
    	printf("Gagal membuka file pemain.txt\n");
        exit(0);
    }

    // Buat file sementara untuk menulis data baru
    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Gagal membuka file temp.txt\n");
        fclose(file);
        exit(0);
    }

    // Baca setiap baris dari file pemain.txt
    while (fgets(line, sizeof(line), file) != NULL) {
        char nomor[10], id[50], password[50];
        sscanf(line, "%s %s %s", nomor, id, password);

        // Jika ID ditemukan
        if (strcmp(id, idtemp) == 0) {
            found = 1; 
            char newPassword[50];

            // Minta user memasukkan password baru
            xy(48,13); printf("Masukan password baru : ");
            scanf("%s", newPassword);

            // Tulis data dengan password baru ke file sementara
            fprintf(tempFile, "%s %s %s\n", nomor, id, newPassword);
        } else {
            // Tulis data lama ke file sementara
            fprintf(tempFile, "%s", line);
        }
    }

    // Tutup kedua file
    fclose(file);
    fclose(tempFile);

    // Ganti file lama dengan file baru
    if (found) {
        remove("pemain.txt");
        rename("temp.txt", "pemain.txt");
        system("cls");
        xy(48,12); printf("Password berhasil diubah.\n"); getche();
        awal();
    } else {
        // Hapus file sementara jika ID tidak ditemukan
        remove("temp.txt");
        system("cls");
        xy(48,12); printf("ID tidak ditemukan.\n"); getche();
        awal();
    }
}


int terdaftar (const char* id) {
    char temp[100];
    char registeredID[50], password[50];
    int nomor;

    FILE* file = fopen("pemain.txt", "r");
    if (file == NULL) {
        return 0;  // File tidak ada, anggap ID belum terdaftar
    }

    while (fgets(temp, sizeof(temp), file) != NULL) {// mindahin satu baris file ke buffer temp
        sscanf(temp, "%d %s %s", &nomor, registeredID, password); // sscanf buat misahin string
        if (strcmp(registeredID, id) == 0) {
            fclose(file);
            return 1;  // ID sudah terdaftar
        }
    }
}

void reg() {
    system("cls");
    system("Color F");
    xy(50, 10); printf("Register");
    xy(40, 12); printf("Buat ID Anda\t\t: ");
    xy(40, 13); printf("Buat Password Anda\t: ");
    xy(67, 12); scanf("%s", pemain.id);
    xy(67, 13); scanf("%s", pemain.password);

    // Periksa apakah ID sudah terdaftar
    if (terdaftar(pemain.id)) {
        xy(40, 15); printf("ID sudah terdaftar\n");
        _getch();
        awal();
    }

    FILE *file = fopen("pemain.txt", "a+"); // Membuka file pemain.txt dengan mode a+ (Open dan read)
    if (file == NULL) {
        xy(40, 15); printf("Error: Tidak dapat membuka file pemain.txt");
        exit(1);
    }

    // Mencari tahu nomor urut terakhir
    fseek(file, 0, SEEK_SET); // Pindah ke awal file
    int user = 0;
    int lastUser = -1;
    char temp[100];

    while (fgets(temp, sizeof(temp), file) != NULL) {
        sscanf(temp, "%d", &lastUser);
    }

    user = lastUser + 1; // Menambah 1 untuk nomor urut berikutnya

    // Menulis nomor urut, ID, dan password ke dalam file
    fprintf(file, "%d %s %s\n", user, pemain.id, pemain.password);
    fclose(file);

    xy(40, 15); printf("Register berhasil, Selamat Datang %s !!", pemain.id);
    _getch();
    awal();
}


void awal ()
{

	char ch;
	int posisi=0;
	const char* pilih[]{"Login", "Register", "Forgot Password", "Exit",};
	
	while(1)
	{ 
	
	 system("cls");
		color (1);
	 for (int i=0; i<4; i++)
	 {
		xy(50,12+i);
		if (i==posisi)
		{
			color(14);
			printf("  %s", pilih[i]);
		}else{
			color(8);
			printf(" %s", pilih[i]);
		}
	 }	
	 xy(1,80); ch = _getche();
	 if (ch== -32)
	 {
	
	 ch = _getche();
	 if (ch == 72)
	  {
	 	posisi--;
	 	if(posisi<0)
	 	{
	 		posisi = 3;
		 }
	  }else if (ch == 80)
	  {
	 	posisi++;
	 	if (posisi>3)
	 	{
	 		posisi = 0;
		 }
	  }
	 }
	 else if (ch == '\r')
	 {
	 	if (posisi==0)
	 	{
	 		login ();
		 }
		 else if (posisi == 1)
		 {
		 	reg();
		 }else if(posisi == 2)
		 {
		 	lupa();
		 }else if(posisi == 3)
		 system("cls");
		 exit(0);
	 }

	}
}


void printWave(int ampli, int wave) {
    char input;
    int totalwave = 5;
   // int totallength = wave * totalwave * 2;

    while(1) {
        system("cls");
        printf(" Amplitudo\t: %d", ampli);
        printf("\n Wavelength\t: %d", wave);
        printf("\n press 'e' to exit\n\n\n\n\n\n");
        for (int i = 0; i < ampli; i++) {
            for (int j = 0; j < 100; j++) {
                int bukit = ((j / wave) % 2 == 0);// lg dibukit apa lembah yaa?

                if (bukit && ampli >1) {
                    if (i == ampli - 1 || j % wave == 0 || j % wave == wave - 1) {// ampli-1 = bawah, j%wave==0 awal, j%wave == wave
                        printf("*");
                    } else {
                        printf(" ");
                    }
                } else if (bukit && ampli<1)//KETIKA AMPLI <1 kenapa gaada print * ya?
                {
                	 if (i == ampli - 1) {// ampli-1 = bawah, j%wave==0 awal, j%wave == akhir wave
                        printf("*");
                    } else {
                        printf(" ");
                    }
                	
				}
				else {
                    if (i == 0) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        input = _getch();
        fflush(stdin);

        if (input == 'S' || input == 's') {
            ampli++;
        } else if (input == 'W' || input == 'w') {
            ampli--;
            if (ampli<1)
            {
            	ampli = 1;
			}

        } else if (input == 'D' || input == 'd') {
            wave++;
        } else if (input == 'A' || input == 'a') {
            wave--;
            if (wave < 1) {
                wave = 1; // Tidak boleh kurang dari 1
            }
        } else if (input == 'E' || input == 'e') {
            break;
        }
    }
}


void loading ()	{
	int dot = 0; 

    for (int i = 0; i < 120; i++) {
    	color(7);
    	xy(2,26); printf("Selamat datang %s harap tunggu", strlwr(pemain.id));
        xy(2,27); printf("loading");
        
        for (int j = 0; j <= dot; j++) { 
         xy(9+j, 27); printf(".");
        }
        
        dot++;
        if (dot == 4) {
		dot = 0;
        }
        
        printf("\n"); 
        
		// LOADING BAR
        for (int k = 0; k < i; k++) { 
        color(2);
         xy(2+k, 28);   printf("%c", 254); 
        }

        Sleep(40);// comment biar ngecek cepet
        system("cls"); 
    } 
    }
    
    void login ()
    {
    	system("Color F");
    	int j;
    	char ch;
    	while (1) {
        system("cls");
        xy(50,10); printf("Login\n");
        xy(47,12); printf("ID\t: ");
        xy(47,13); printf("Password\t: ");
        
        xy(59,12); fgets(pemain.id, sizeof(pemain.id), stdin); fflush(stdin);//scan id dari user
        pemain.id[strcspn(pemain.id, "\n")] = 0; //hapus \n dari input
        
        //SCAN PASSWORD SEKALIGUS PRINT *
        xy(59, 13);
        j = 0;
        while ((ch = _getch()) != 13) { // 13 adalah ascii \r
            if (ch == 8) { // 8 ascii backspace
                if (j > 0) { 
                     j--;
                    printf("\b \b"); // replace bintang dengan sepasi
                }
            } else/* if (ch != 13) */{ 
                pemain.password[j++] = ch;
                printf("*");
            }
        }
        pemain.password[j] = '\0';
        
        //Cek ID Kosong apa tidak
        if (strlen(pemain.id) == 0) {
            xy(47,15); printf("ID tidak boleh kosong");
            getche();
            continue; // ulangin loop
        }
        
        //Cek Password Kosong apa tidak
        if (strlen(pemain.password) == 0) {
            xy(47,15); printf("Password tidak boleh kosong");
            getche();
            continue; // ulangin loop
        }

        // MEMBUKA FILE pemain.txt untuk login
        FILE *file = fopen("pemain.txt", "r");
        if (file == NULL) {
            xy(47,15); printf("Error: Tidak Dapat Membuka File");
            exit(1);
        }

        char file_id[100], file_password[100];
        int user, login = 0;
        
        while (fscanf(file, "%d %s %s", &user, file_id, file_password) != EOF) {
            if (strcmp(pemain.id, file_id) == 0 && strcmp(pemain.password, file_password) == 0) {
               // BERHASIL LOGIN
               //test();
               
                login = 1;
                xy(47,15); printf("LOGIN BERHASIL, SILAHKAN %s!!!", strupr(pemain.id));
                getche();
                loading ();
                color(10);  
                menu();
                printMenu(0);
            }
        }
        if (!login) {
            xy(47,15); printf("DATA TIDAK DIKENAL, PROGRAM DIHENTIKAN");
            exit(0);
        }
        fclose(file);
        break;
         
    }

	}


  void xy(int x, int y) { //fungsi set posisi
    printf("\033[%d;%dH",y,x);
}



int main () {
   
    awal();
    // LOGIN
	login ();
   // MENU
   menu();
 
    return 0;
}


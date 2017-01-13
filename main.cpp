#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream inp;
ofstream outp;

char afisaj[30][25],vp1[30][25];
int verifica[30][25];
int highscore1,highscore2,highscore3;
int contr,tasta=0,scor=0,timp=0,cadere=0,birdx=0,birdy=0,inceput;
bool eroare,powerup1,powerup2,powerup3;

void game();
void screen();
void pipes();
void bird();
bool gameover();
void verificascor();
void ajutor();
void meniu();
void sfarsitjoc();
void scoruri();

class timer {
	public:
		timer();
		void           start();
		void           stop();
		void           reset();
		bool           isRunning();
		unsigned long  getTime();
		bool           isOver(unsigned long seconds);
	private:
		bool           resetted;
		bool           running;
		unsigned long  beg;
		unsigned long  end;
};

timer::timer() {
	resetted = true;
	running = false;
	beg = 0;
	end = 0;
}


void timer::start() {
	if(! running) {
		if(resetted)
			beg = (unsigned long) clock();
		else
			beg -= end - (unsigned long) clock();
		running = true;
		resetted = false;
	}
}


void timer::stop() {
	if(running) {
		end = (unsigned long) clock();
		running = false;
	}
}


void timer::reset() {
	bool wereRunning = running;
	if(wereRunning)
		stop();
	resetted = true;
	beg = 0;
	end = 0;
	if(wereRunning)
		start();
}


bool timer::isRunning() {
	return running;
}


unsigned long timer::getTime() {
	if(running)
		return ((unsigned long) clock() - beg)/ CLOCKS_PER_SEC;
	else
		return end - beg/ CLOCKS_PER_SEC;
}


bool timer::isOver(unsigned long seconds) {
	return seconds >= getTime();
}


timer t,ht1,ht2,ht3;
void verificascor()
{
    int y;
    for(y=0;y<24;y++)
    {
        if(afisaj[birdx][y]=='|')
        {
            scor++;
            return;
        }
    }
}
void verificapowerup1()
{

        if(afisaj[birdx][birdy]=='&')
        {
            powerup1=1;
            return;
        }

}
bool lovestetuburi()
{
    int ok=0;
    if(birdy>23)
    {
        afisaj[birdx][23]='*';
        afisaj[birdx][24]='-';
        ok=1;
        goto control;
    }
    else
    {
        if((afisaj[birdx][birdy]=='|' || afisaj[birdx][birdy]=='*') && verifica[birdx][birdy]!=0)
        {
            afisaj[birdx][birdy]='|';
            afisaj[birdx-1][23]='*';
            ok=1;
            goto control;
        }
    }
    control:
    if(ok==1) return true;
    else return false;
}

void sfarsitjoc()
{
    screen();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout<<""<<endl<<endl;
    cout<<" ------------------------------------------------------------------------- "<<endl;
    cout<<"|    *****      *     *       * ******       ****  *       ****** ****    |"<<endl;
    cout<<"|   *          * *    * *   * * *           *    *  *     * *     *   *   |"<<endl;
    cout<<"|   *  ****   *   *   *  * *  * *****       *    *   *   *  ****  ****    |"<<endl;
    cout<<"|   *  *  *  *******  *   *   * *           *    *    * *   *     * *     |"<<endl;
    cout<<"|    *****  *       * *       * ******       ****      *    ***** *   *   |"<<endl;
    cout<<" ------------------------------------------------------------------------- "<<endl;
    cout<<""<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"                        S C O R U L   T A U : "<<scor<<endl;
    cout<<"                        T I M P U L   T A U : "<<t.getTime()<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<"          C E L   M A I   M A R E   S C O R : "<<highscore1<<endl;
     cout<<"                                   T I M P : "<<ht1.getTime()<<endl;
    cout<<""<<endl<<endl;
}
void meniu()
{


    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<""<<endl;
    cout<<" --------------------------------------------------------  "<<endl;
    cout<<"|                                                        | "<<endl;
    cout<<"|   **** *    **** **** **** *   *    ***  * ***  ***    | "<<endl;
    cout<<"|   *    *    *  * *  * *  * *   *    *  * * *  * *  *   | "<<endl;
    cout<<"|   ***  *    **** **** **** *****    ***  * ***  *  *   | "<<endl;
    cout<<"|   *    *    *  * *    *      *      *  * * *  * *  *   | "<<endl;
    cout<<"|   *    **** *  * *    *      *      ***  * *  * ***    | "<<endl;
    cout<<" --------------------------------------------------------  "<<endl;
    cout<<""<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<"                  Cel mai bun scor:  "<<highscore1<<endl<<endl;
    cout<<""<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout<<"                   M E N I U:    "<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"                  1: Incepe jocul"<<endl<<endl;
    cout<<"                  2: Ajutor        "<<endl<<endl;
    cout<<"                  3: Exit        "<<endl<<endl;
    cout<<"                  4: Leader Board "<<endl<<endl;
}



void scoruri()
{
    system("cls");
    char scrie;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    cout<<""<<endl;
    cout<<" -----------------------------------------------------------------------  "<<endl;
    cout<<"|                                                                       | "<<endl;
    cout<<"|   *    ***     *     ***  *** ***      ***    **      *     ***  ***  | "<<endl;
    cout<<"|   *    *      * *    *  * *   *  *     *  *  *   *   * *    *  * *  * | "<<endl;
    cout<<"|   *    ***   *****   *  * *** ***      ***  *     * *****   ***  *  * | "<<endl;
    cout<<"|   *    *    *     *  *  * *   * *      *  *  *   * *     *  * *  *  * | "<<endl;
    cout<<"|   ***  *** *       * ***  *** *  *     ***    **  *       * *  * ***  | "<<endl;
    cout<<" -----------------------------------------------------------------------  "<<endl;
    cout<<""<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout<<"                  1st:  "<<highscore1<<"      "<<ht1.getTime()<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),07);
    cout<<"                  2nd:  "<<highscore2<<"      "<<ht2.getTime()<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),04);
    cout<<"                  3rd:  "<<highscore3<<"      "<<ht3.getTime()<<endl<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    cout<<"Mergi inapoi? [da/nu]  ";
    cin>>scrie;

    if(scrie=='d') return;
    else system("cls");
    }



void ajutor()
{
    char scrie;
    system("cls");
    while(true)
    {
        //setConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
    cout<<""<<endl<<endl;
    cout<<"                               Ajutor                         "<<endl;
    cout<<endl;
    cout<<"                   Apasati orice tasta pentru a zbura.        "<<endl<<endl;
    cout<<"             Scopul este de a trece prin cat mai multe tuburi "<<endl;
    cout<<"           fara a le atinge.Daca lovesti un tub, trebuie sa o "<<endl;
    cout<<"           iei de la capat.                                   "<<endl;
    cout<<"             Fii atent! Nu lovi tuburile sau pamantul!        "<<endl<<endl;
    cout<<"                          Esti gata sa incepi?                "<<endl<<endl<<endl;
    cout<<"Mergi inapoi? [da/nu]  ";
    cin>>scrie;

    if(scrie=='d') return;
    else system("cls");
    }
}

int main()
{
srand(time(0));
inp.open("/Users/blues/Desktop/tema/Scor.txt");
if(inp.is_open())
{   long a=ht1.getTime(),b=ht2.getTime(),c=ht3.getTime();
    inp>>highscore1>>a>>highscore2>>b>>highscore3>>c;
    inp.close();
    eroare=false;
}
else
{
    highscore1=0; highscore2=0; highscore3=0;
    eroare=true;
}

int NrJocuri=0;
char scrie;
while(1)
{
    if(NrJocuri==0) goto joc;
    if(NrJocuri>0)
    {
        scor=0;
        cout<<"Vrei sa joci din nou? [da/nu] ";
        cin>>scrie;
        if(scrie=='n') goto iesire;
        else goto joc;
    }
    joc:
    meniu();
    cin>>scrie;
    if( scrie=='1')
        {
            game();
            break;
        }
        else if(scrie=='2')
        {
            ajutor();
            goto joc;
            break;
        }

        else if(scrie=='3')
        {
            goto iesire;
            break;
        }
        if( scrie=='4')
        {
            scoruri();
            goto joc;
            break;
        }
        else
        {
            goto joc;
            break;
        }

    NrJocuri++;
}
iesire:
{
   cout<<"Ies din joc.";
}

return 0;
}

void game()
{
    int x,y;
    char s;

    for(y=0;y<25;y++)
    {
        for(x=0;x<30;x++)
        {
            if(y<24)
            {
            afisaj[x][y]=' ';
            verifica[x][y]=0;
            }
            if(y==24)
            {
                afisaj[x][y]='-';
                verifica[x][y]=2;
            }
        }
    }
    afisaj[10][10]='*';
    screen();
    while(1)
    {
        t.start();
        s='~';
        Sleep(0.2*1000);
        timp++;
        if(kbhit())
        {
            s=getch();
            if(s!='~') tasta=1;
        }
        for(x=0;x<30;x++)
        {
            afisaj[x][24]='-';
            verifica[x][24]=2;
        }
        bird();
        verificascor();
        verificapowerup1();
        if(powerup1==1)
        {
            inceput=t.getTime();

        }
        if(lovestetuburi()==true && powerup1==0) {
                goto sfarsit;
                if(t.isRunning())
					t.stop();  }
        else if(lovestetuburi()==true && powerup1==1 && inceput<=10+t.getTime())
        { scor++; }
            else if(powerup1=1 && inceput+11==t.getTime())
            {
                powerup1=0;
            }
        pipes();
        if(scor>highscore1){
                highscore3=highscore2;
                highscore2=highscore1;
                highscore1=scor;
                ht1=t;} //hightscoretime1
        if(scor>highscore2){
                highscore3=highscore2;
                highscore2=scor;
                ht2=t;}
        if(scor>highscore3){
                highscore3=scor;
                ht3=t;}
        screen();
        if(tasta>0) tasta++;
        if(tasta==3) tasta=0;
    }
    sfarsit:
    {
        if(scor>highscore1){
                highscore3=highscore2;
                highscore2=highscore1;
                highscore1=scor;
                ht1=t;}
        if(scor>highscore2){
                highscore3=highscore2;
                highscore2=scor;
                ht2=t;}
        if(scor>highscore3){
                highscore3=scor;
                ht3=t;}
        if(eroare==false)
        {

            outp.open("/Users/blues/Desktop/tema/Scor.txt");
            outp<<highscore1<<" "<<ht1.getTime()<<endl<<highscore2<<" "<<ht2.getTime()<<endl<<highscore3<<" "<<ht3.getTime()<<endl;
            outp.close();
        }
        screen();
        //t.reset();
        sfarsitjoc();
        return;
    }
}

void screen()
{
    int x,y;
    system("cls");


    for(y=0;y<25;y++)
    {
        for(x=0;x<30;x++)
        {
            if(x<29) cout<<afisaj[x][y];
            if(x==29) cout<<afisaj[x][y]<<endl;
        }
    }

    cout<<""<<endl;
    cout<<"Scorul tau: "<<scor;
    cout<<endl;
    cout<<"Timp : "<<t.getTime() << " secunde";

}

void pipes()
{
    int x,y,r;
    if(timp==10)
    {
        r=(rand()%11)+5;
        for(y=0;y<24;y++)
        {
            afisaj[29][y]='|';
            verifica[29][y]=2;
        }
        afisaj[29][r-1]=' ';
        afisaj[29][r]=' ';
        afisaj[29][r+1]=' ';
        verifica[29][r-1]=0;
        verifica[29][r]=0;
        verifica[29][r+1]=0;
        timp=0;
        goto deplasare;
    }
    else goto deplasare;
    deplasare:
    {
        for(y=0;y<24;y++)
        {
            for(x=0;x<30;x++)
            {
                if(afisaj[x][y]=='|')
                {
                    if(x>0)
                    {
                        afisaj[x-1][y]='|';
                        verifica[x-1][y]=2;
                        afisaj[x][y]=' ';
                        verifica[x][y]=0;
                    }
                    if(x==0)
                    {
                        afisaj[x][y]=' ';
                        verifica[x][y]=0;
                    }
                }
            }
        }
    }
}

void bird()
{
    int x,y;
    if(tasta>0)
    {
        cadere=0;
        for(y=0;y<24;y++)
        {
            for(x=0;x<30;x++)
            {
                if(afisaj[x][y]=='*')
                {
                    if(y>0)
                    {
                    afisaj[x][y-1]='*';
                    afisaj[x][y]=' ';
                    birdx=x;
                    birdy=y-1;
                    return;
                    }
                }
            }
        }
    }
    else
    {
        cadere++;
        for(y=0;y<24;y++)
        {
            for(x=0;x<30;x++)
            {
                if(afisaj[x][y]=='*')
                {
                    if(y<24)
                    {
                        if(cadere<3)
                        {
                            afisaj[x][y+1]='*';
                            afisaj[x][y]=' ';
                            birdx=x;
                            birdy=y+1;
                            return;
                        }
                        else if(cadere>2 && cadere<5)
                        {
                            afisaj[x][y+2]='*';
                            afisaj[x][y]=' ';
                            birdx=x;
                            birdy=y+2;
                            return;
                        }
                        else if(cadere>4)
                        {
                            afisaj[x][y+3]='*';
                            afisaj[x][y]=' ';
                            birdx=x;
                            birdy=y+3;
                            return;
                        }
                    }
                    else
                    {
                        return;
                    }
                }
            }
        }
    }
}

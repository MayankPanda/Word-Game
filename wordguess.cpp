# include <fstream.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>
# include <stdio.h>
# include <process.h>
class word
{
int wi,nol;
char w[25],c1[100];
public:
word()
{
nol=0;
w[25]='\0';
c1[25]='\0';
wi=0;
}
word (word &s)
{
wi=s.wi;
nol=s.nol;
strcpy(w,s.w);
strcpy(c1,s.c1);
}
void accept()
{
cout<<"ACCEPT WORD INDEX:";
cin>>wi;
cout<<"ACCEPT NUMBER OF LETTERS";
cin>>nol;
cout<<"ACCEPT WORD";
gets(w);
cout<<"ACCEPT CLUE";
gets(c1);
}
void display()
{
cout<<"WORD INDEX:"<<wi<<endl;
cout<<"WORD:"<<w<<endl;
cout<<"NUMBER OF LETTERS"<<nol<<endl;
cout<<"CLUE:"<<c1<<endl;
}
void show1()
{
cout<<"NUMBER OF LETTERS: "<<nol<<endl;
cout<<"CLUE:"<<endl<<c1<<endl;
}
char* retword()
{
return w;
}
};
void player();
void count();
void create();
void addword();
void didisp();
void admins();
void main()
{
int ca,pass=268,dm;
clrscr();
count();
cout<<"WELCOME TO WORD GUESSING GAME:";
cout<<endl;
cout<<"CHOOSE ACCOUNT:"<<endl;
cout<<"1.PLAYER             2.ADMINISTRATOR"<<endl;
cout<<"ACCEPT CHOICE";
cin>>ca;
switch(ca)
{
 case 1:
 player();
 break;
 case 2:
 cout<<"ENTER PASSWORD";
 cin>>dm;
 if (dm==pass)
 {
 admins();
 }
 else
 {
 cout<<"WRONG PASSWORD";
 exit(0);
 }
 break;
 default:
 cout<<"WRONG CHOICE";
 exit(0);
}
getch();
}
void player()
{
  int i,r,wr=0,rg=0,point=0,un=0;
  word w;
  char dm[25];
  ifstream ir("wordstore1.dat",ios::binary);
  cout<<"WELCOME PLAYER"<<endl;
  cout<<"LETS BEGIN WITH THE GAME";
  cout<<endl;
  cout<<"THE RULES ARE:"<<endl;
  cout<<"1.YOU WILL BE GIVEN A FEW WORDS TO GUESS"<<endl;
  cout<<"2.IF YOU GUESS ON THE FIRST CLUE YOU WILL GET 20 POINTS"<<endl;
  cout<<"3.THERE IS NEGATIVE MARKING"<<endl;
  cout<<"4IF YOU GET THE WORD WRONG AT THE FIRST CLUE THEN YOU WILL GET -4 NEGATIVE MARKS:";
  cout<<endl;
  cout<<"5.YOU CAN CHOOSE NOT TO ATTEMPT A WORD THEN YOU WILL GET NO POINTS";
  cout<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"LET'S START";
  while (ir.read((char*)&w,sizeof(w)))
  {
  clrscr();
  w.show1();
  cout<<"YOU HAVE THREE OPTIONS:"<<endl;
  cout<<"1.ATTEMPT"<<endl;
  cout<<"2.LEAVE"<<endl;
  cout<<"3.EXIT"<<endl;
  cout<<"MAKE YOUR CHOICE: ";
  cin>>r;
  switch(r)
  {
  case 1:
  {
  cout<<"ENTER WORD ";
  gets(dm);
  if (strcmpi(w.retword(),dm)==0)
  {
  cout<<"CONGRATULATIONS YOU HAVE GOT THE RIGHT WORD: ";
  point+=20;
  rg++;
  cout<<"PRESS ANY KEY TO CONTINUE: ";
  getch();
  }
  else
  {
  cout<<"WRONG WORD";
  cout<<endl;
  wr++;
  point-=4;
  cout<<"THE CORRECT WORD IS "<<w.retword();
  cout<<endl;
  cout<<"PRESS ANY KEY TO CONTINUE ";
  getch();
  }
  }
  break;
  case 2:
  cout<<"THE CORRECT WORD WAS: "<<w.retword();
  un++;
  cout<<"PRESS ANY KEY TO CONTINUE ";
  getch();
  break;
  case 3:
  cout<<"THANK YOU ";
  cout<<"YOUR SCORE WAS: "<<point;
  cout<<endl;
  cout<<"NUMBER OF RIGHT ANSWERS: "<<rg<<endl;
  cout<<"NUMBER OF WRONG ANSWERS "<<wr<<endl;
  cout<<"NUMBER OF UNATTEMPTED WORDS "<<un<<endl;
  getch();
  exit(0);
  default:
  getch();
  exit(0);
 }
 }
 cout<<"YOUR TOTAL SCORE IS: "<<point;
 cout<<"NUMBER OF RIGHT ANSWERS: "<<rg<<endl;
 cout<<"NUMBER OF WRONG ANSWERS" <<wr<<endl;
 cout<<"NUMBER OF UNATTEMPTED WORDS "<<un<<endl;
 ir.close();
 }
 void admins()
 {
 int c;
 cout<<"WELCOME ADMINISTRATOR";
 cout<<endl;
 cout<<"SELECT TASK";
 cout<<endl;
 cout<<"1.DISPLAY DICTIONARY"<<endl;
 cout<<"2.ADD WORD"<<endl;
 cout<<"ACCEPT CHOICE: ";
 cin>>c;
 switch(c)
 {
 case 1:
 didisp();
 break;
 case 2:
 addword();
 break;
 default:
 exit(0);
 }
 }
 void didisp()
 {
 word w;
 ifstream i("wordstore.dat",ios::binary);
 while (i.read((char*)&w,sizeof(w)))
 {
 w.display();
 }
 i.close();
 }
 void addword()
 {
  word w;
  ofstream o("wordstore.dat",ios::binary|ios::app);
  cout<<"WORD ADDITION"<<endl;
  cout<<endl;
  char ch='y';
  while((ch=='y')||(ch=='Y'))
  {
   w.accept();
   o.write((char*)&w,sizeof(w));
   cout<<"DO YOU WANT TO CONTINUE:";
   cin>>ch;
  }
  o.close();
 }
 void create()
 {
 ofstream o;
 word w;
 o.open("wordstore.dat",ios::binary);
 char ch='y';
 while ((ch=='y')||(ch=='Y'))
 {
 w.accept();
 o.write((char*)&w,sizeof(w));
 cout<<"DO YOU WANT TO CONTINUE";
 cin>>ch;
 }
 o.close();
 }
void count()
 {
 cout<<"FUNCTION TO COUNT THE NUMBER OF RECORDS"<<endl;
 ifstream i;
 word w;
 int c=0;
 i.open("wordstore.dat",ios::binary);
 while ((i.read((char*)&w,sizeof(w))))
 {
  c++;
 }
 cout<<"NUMBER OF RECORDS:  "<<c<<endl;
 if (c==0)
 {
 cout<<"CREATE FUNCTION REQUIRED:"<<endl;
 create();
 }
 else
 {
 cout<<"CREATE FUNCTION NOT REQUIRED"<<endl;
 }
 i.close();
 }


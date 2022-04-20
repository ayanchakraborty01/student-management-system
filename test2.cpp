#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>

using namespace std;
int adm = 0;
class Student
{
 int admno;
 char name[20];
 char gender;
 int std;
 float marks;
 float percentage;

 public:
  void getData();
  void showData();
  int getAdmno(){return admno;}
}s;

void Student::getData()
{ system("color f");
 cout<<"\n\nEnter Student Details......\n";
    admno = adm;
 cout<<"Enter Full Name         : "; cin.ignore(); cin.getline(name,20);
 cout<<"Enter Gender (M/F)      : "; cin>>gender;
 cout<<"Enter Standard          : "; cin>>std;
 cout<<"Enter Marks (out of 500): "; cin>>marks;
 cout<<endl;
 percentage=marks*100.0/500.00;
}

void Student::showData()
{	system("color f");
 cout<<"\n\n.......Student Details......\n";
 cout<<"Admission No.     : "<<admno<<endl;
 cout<<"Full Name         : "<<name<<endl;
 cout<<"Gender            : "<<gender<<endl;
 cout<<"Standard          : "<<std<<endl;
 cout<<"Marks (out of 500): "<<marks<<endl;
 cout<<"Percentage        : "<<percentage<<endl;
 cout<<endl;
}

void addData()
{	system("color 9");
 ofstream fout;
 fout.open("Students.dat",ios::binary|ios::out|ios::app);
 adm++;
 s.getData();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"\n\nData Successfully Saved to File....\n";
 cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void displayData()
{
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 if(!fin.is_open())
 {
     cerr<<"could not open file"<<endl;
 }
 else if(fin.peek()== EOF)
 {
     cout<<"File is empty"<<endl;
 }
 else {
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.showData();
    }
    fin.close();
    cout<<"\n\nData Reading from File Successfully Done....\n";
 }
 cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void searchData()
{	system("color B");
 int n, flag=0;
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 if(!fin.is_open())
 {
     cerr<<"could not open file"<<endl;
 }
 else if(fin.peek()== EOF)
 {
     cout<<"File is empty"<<endl;
 }
 else {
 cout<<"Enter Admission Number you want to search : ";
 cin>>n;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"The Details of Admission No. "<<n<<" shown herewith:\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 cout<<"\n\nData Reading from File Successfully Done....\n";
 }
 cout<<"press any key to continue...";
		cin.ignore();
            cin.get();
}

void deleteData()
{	system("color 4");
 int n, flag=0;
 ifstream fin;

 ofstream fout,tout;

 fin.open("Students.dat",ios::in|ios::binary);
 if(!fin.is_open())
 {
     cerr<<"could not open file"<<endl;
 }
 else if(fin.peek()== EOF)
 {
     cout<<"File is empty"<<endl;
 }

 else {
 fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
 tout.open("TrashStud.dat",ios::out|ios::app|ios::binary);




 cout<<"Enter Admission Number you want to move to Trash : ";
 cin>>n;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"The Following Admission No. "<<n<<" has been moved to Trash:\n";
   s.showData();
   tout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 remove("Students.dat");
 rename("tempStud.dat","Students.dat");
 }
 cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void getTrash()
{	system("color 1");
 ifstream fin;
 fin.open("TrashStud.dat",ios::in|ios::binary);
  if(!fin.is_open())
 {
     cerr<<"could not open file"<<endl;
 }
 else if(fin.peek()== EOF)
 {
     cout<<"File is empty"<<endl;
 }
else{
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nData Reading from Trash File Successfully Done....\n";
}
 cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void modifyData()
{	system("color a");
 int n, flag=0, pos;
 fstream fio;

 fio.open("Students.dat",ios::in|ios::out|ios::binary);
 if(!fio.is_open())
 {
     cerr<<"could not open file"<<endl;
 }
 else if(fio.peek()== EOF)
 {
     cout<<"File is empty"<<endl;
 }
else{
 cout<<"Enter Admission Number you want to Modify : ";
 cin>>n;

 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getAdmno())
  {
   cout<<"The Following Admission No. "<<n<<" will be modified with new data:\n";
   s.showData();
   cout<<"\n\nNow Enter the New Details....\n";
   s.getData();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();

 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
}
  cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void mainmenu()
{
 int ch;

  system("color c");
  cout<<"\t\t\t\t=================MAIN MENU================\n"<<endl;
  cout<<"\t\t\t======================================================\n\n";
  cout<<"\t\t\t\t1. ADD NEW STUDENT\n\n";
  cout<<"\t\t\t\t2. DISPLAY ALL STUDENT INFO\n\n";
  cout<<"\t\t\t\t3. DISPLAY A SINGLE STUDENTS INFO\n\n";
  cout<<"\t\t\t\t4. DELETE RECORD FROM FILE\n\n";
  cout<<"\t\t\t\t5. GET DELETED RECORD FROM TRASH FILE\n\n";
  cout<<"\t\t\t\t6. MODIFY DATA\n\n";
  cout<<"ENTER YOUR CHOICE  : ";
  cin>>ch;
  system("cls");
  switch(ch)
  {
   case 1: addData(); break;
   case 2: displayData(); break;
   case 3: searchData(); break;
   case 4: deleteData(); break;
   case 5: getTrash(); break;
   case 6: modifyData(); break;
  }
	 system("pause");
}

void intro()
{
	cout << "\n\n\n";
    Sleep(100);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(100);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(100);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(100);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(100);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(100);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(100);
    cout<<"\t\t\t\tTHIS IS STUDENT  MANEGEMENT SYSTEM"<<endl;
    Sleep(100);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(300);
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

int main()
{
 system("color a");
    char c;
    system("cls");
    intro();

    do{
   system("cls");
   system("color e");
   cout<<"\n\n";
   cout<<"\t====================STUDENT  MANEGEMENT SYSTEM===================="<<endl;
   cout<<endl;
   cout<<"\t\t\t\t1. MAIN MENU\n\n";
   cout<<"\t\t\t\t2. EXIT\n\n";
   cout<<"ENTER YOUR CHOICE :";
   cin>>c;
   system("cls");
   switch(c)
   {
   case '1':
    {
        mainmenu();
        break;
    }

   }
    }while(c!='2');
    return 0;
}

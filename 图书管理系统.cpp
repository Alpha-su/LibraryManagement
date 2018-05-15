#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include<stdio.h>
using namespace std;
char show_content[500];
char book_name[50];
char ID_name[20];
char SHOW[200];
int number;
char oldname[] ="chengshe.txt";

class Book{
public:
	Book(char *book_name);
	//void Borrow(char *book_name);
	//void Return(char *book_name);
	void Enter(char *book_name);
	//char Research(char book_name);
	void Read(char *book_name); 
	void Download(char *book_name);
private:
	string ISBN;
	char name[20];
	string publisher;
	//int type;
	char content[10000];
	string depository;
}; 
Book::Book(char *book_name){
	strcpy(name,book_name);
}
void Book::Enter(char *book_name){
	ofstream booknames("booknames.txt");
	booknames<<book_name<<endl;
	booknames.close();
	ofstream enter (book_name);									//录入的数据写到文件里  
	enter<<"the book is in library"<<endl;
	enter<<"type:1" <<endl;
	enter<<book_name<<endl;
	cout<<"enter the ISBN"<<endl;
	cin>>ISBN;enter<<ISBN<<endl;
	cout<<"enter the publisher"<<endl;
	cin>>publisher;enter<<publisher<<endl;
	cout<<"enter the depository"<<endl;
	cin>>depository;enter<<depository<<endl;
	cout<<"enter the content"<<endl;
	//getchar(); 
	cin.getline(content,1000);
	enter<<content<<endl;	
	enter.close();
	/*strcpy(name[sum],book_name);
	Number[sum]=number;
	sum++;*/
	/*ofstream booknames("booknames.txt");
	if(!booknames)	cout<<"error";
	booknames<<book_name<<" ";									//书的名字存到booknames文件中	
	*/
}
void Book::Read(char *book_name){
	ifstream in (book_name);
	if(!in){
		cout<<"no this book"<<endl; 
		return ;
	}	
	in.getline(show_content,500);
	in.getline(show_content,500);
	in.getline(show_content,500);
	in.getline(show_content,500);
	in.getline(show_content,500);
	in.getline(show_content,500);
	cout<<"content:"<<endl;
	char P; 
	while (!in.eof()){
		for(int i=0;i<60;i++)
		{
			in.get(P);
			cout<<P;
		}
		cout<<endl;	
	}
	in.close();
	} 
/*void Book::Borrow(char *book_name){
	ifstream in (book_name);
	if(!in){
		cout<<"no this book,you can not borrow"<<endl; 
		return;
	}	
}*/
/*void Book::Download(char *book_name);{
	ifstream in(book_name);
	if(!in){
		cout<<"no this book"<<endl; 
		return 0;
	}	
	in.getline(show_content,500);
	in.getline(show_content,500);
	in.getline(show_content,500);
	in.getline(show_content,500);
	cout<<show_content <<endl;	
	in.close();
}*/
/*void Book::Return (char *book_name){
	int i;
	for(i=0;i<sum;i++){
		if (strcmp(book_name,name [i])==0);
		break;	
	}
	Number[i]++;
	cout<<"You have returned the book!"<<endl;
}*/
///
class UserManager
{
public: 
    void createUser(char *ID_name);
    //User loadUser(string name);
    //void deleteUser(char *ID_name);
private:
	string password;
	string role;
};
void UserManager::createUser(char *ID_name){
	cout<<"Please enter your password"<<endl;
	cin>>password; 
	ofstream user(ID_name);
	user<<ID_name<<endl<<password<<endl<<"user"<<endl; 
	user.close();
	cout<<"the user is created"<<endl;
}
///
class User
{
public:
	void Borrow(char *ID_name,char *Q);
	void Return(char *ID_name,char *Q);
    void update(char *book_name);
    void Delete(char *book_name);
    void Search(char *Q);
	//void getinfo(char *ID_name);
private:
    string _name;
    string _pass;
    string _role;
};
void User::update(char *book_name){
	int num;
	cout<<"enter the type.电子书：1;实体书:0"<<endl;
	cin>>number;
	if(number==1){
		  ifstream in(book_name);
		  if(!in){
		  	cout<<"no this book"<<endl;
		  	return ;}
		  	else{
		  		ofstream out("chengshe.txt");
		  cout<<"if you want to update ISBN,enter 0"<<endl;
		  cout<<"if you want to update depository,enter 1"<<endl;
		  cin>>num;
		  cout<<"enter the new"<<endl;
		  char Q[20];cin>>Q;
		  if(num==0)
		  {
			in.getline(SHOW,500);
			out<<SHOW<<endl;
			in.getline(SHOW,500);
			out<<SHOW<<endl;
			in.getline(SHOW,500);
			out<<SHOW<<endl;
			in.getline(SHOW,500);
			out<<Q<<endl;
			while (!in.eof()){
			in.getline(show_content,500);
			out<<show_content <<endl;	
			}
			in.close();
			out.close();
			remove(book_name);
			if(rename("chengshe.txt",book_name)==0)	cout<<"get it."<<endl;
			else	cout<<"error"<<endl;
		  }
		  else{
		  	in.getline(SHOW,500);
			out<<SHOW<<endl;
			in.getline(SHOW,500);
			out<<SHOW<<endl;
			in.getline(SHOW,500);
			out<<SHOW<<endl;
			in.getline(SHOW,500);
			out<<SHOW<<endl;
			in.getline(SHOW,500);
			out<<SHOW<<endl;
			out<<Q<<endl;
			while (!in.eof()){
			in.getline(show_content,500);
			out<<show_content <<endl;
			}
			in.close();
			out.close();
			remove(book_name);
			if(rename("chengshe.txt",book_name)==0)	cout<<"get it."<<endl;
		}
	}
			  }
	else{
		//实体书的更新；
		ifstream in(book_name);
		if(!in)	{
			cout<<"no this book"<<endl;
			return ;
		}
		else{
			cout<<"enter the ISBN new"<<endl; 
		string Q;cin>>Q;
		ofstream out("chengshe.txt");
		in.getline(SHOW,500);
		out<<SHOW<<endl;
		in.getline(SHOW,500);
		out<<SHOW<<endl;
		in.getline(SHOW,500);
		out<<SHOW<<endl;
		in.getline(SHOW,500);
		out<<Q<<endl;
		in.getline(SHOW,500);
		out<<SHOW <<endl;
		in.close();
		out.close();
		remove(book_name);
		if(rename("chengshe.txt",book_name)==0)	cout<<"get it."<<endl;
		}
	}
}
void User::Delete(char *book_name)
{
	ifstream in(book_name);
	if(!in)
	{
		cout<<"no this book"<<endl;
		return ;
	}
	in.close();
	if(remove(book_name)==0)
	{
		cout<<"the book is deleted"<<endl;
	}
}
void User::Borrow(char *ID_name,char *Q){
	ifstream in(Q);
	if(!in)
	{
		cout<<"no this book "<<endl;
		return ;
	}
	in.getline(show_content,500);
	if(strcmp(show_content,"the book is in library")!=0) {
		cout<<show_content<<endl;
		return;
	}
	in.getline(show_content,500);
	if(strcmp(show_content,"type:1")==0){
		cout<<"this is ebook,no borrow"<<endl;
		return;
	}
	in.close();
	in.open(Q);
	ofstream out("chengshe.txt");
	in.getline(SHOW,500);
	out<<"the book is in "<<ID_name<<"'s hand"<<endl;
	while (!in.eof()){
			in.getline(show_content,500);
			out<<show_content <<endl;
			}
			in.close();
			out.close();
			remove(Q);
			if(rename(oldname,Q)==0)	cout<<"get it."<<endl;
}
void User::Return(char *ID_name,char *Q){
	ifstream in(Q);
	if(!Q)
	{
		cout<<"no this book "<<endl;
		return ;
	}
	in.getline(show_content,500);
	in.getline(show_content,500);
	if(strcmp(show_content,"type:1")==0){
		cout<<"this is ebook,no return"<<endl;
		return;
	}
	in.close();
	in.open(Q);
	ofstream out("chengshe.txt");
	in.getline(SHOW,500);
	out<<"the book is in library"<<endl;
	while (!in.eof()){
			in.getline(show_content,500);
			out<<show_content <<endl;
			}
			in.close();
			out.close();
			remove(Q);
			if(rename("chengshe.txt",Q)==0)	cout<<"get it."<<endl;
}
void User::Search(char *Q){
	ifstream inn("booknames.txt");
			if(!inn){
				cout<<"error"<<endl;
				return ;
			}
			char *p;
			while(!inn.eof()){
				inn.getline(SHOW,500);
				p=strstr(SHOW,Q);
				if(p!=NULL){
					ifstream in(SHOW);
					in.getline(show_content,500);
					cout<<show_content<<endl;
					in.getline(show_content,500);
					cout<<show_content<<endl;
	in.getline(show_content,500);
	cout<<show_content<<endl;
	in.getline(show_content,500);
	cout<<show_content<<endl;
	in.getline(show_content,500);
	cout<<show_content<<endl;
	in.getline(show_content,500);
	cout<<show_content<<endl;
	//cout<<"content:"<<endl;
	char P; 
	while (!in.eof()){
		for(int i=0;i<60;i++)
		{
			in.get(P);
			cout<<P;
		}
		cout<<endl;	
	}
					in.close();
					return;
				}
			}
			inn.close();
			cout<<"no this key"<<endl;
}
///
class paper{
public:
	paper(char *bookname);
	void Enter(char *book_name);
	void Read(char *book_name);
private:
	string ISBN;
	char name[20];
	string publisher;
	//int type;
	string content;
} ;
paper::paper(char *book_name){
	strcmp(name,book_name);
}
void paper::Enter(char *book_name){
	ofstream booknames("booknames.txt");
	booknames<<book_name<<endl;
	booknames.close();
	ofstream enter (book_name);									//录入的数据写到文件里  
	enter<<"the book is in library"<<endl;
	enter<<"type:0"<<endl;
	enter<<book_name<<endl;
	cout<<"enter the ISBN"<<endl;
	cin>>ISBN;enter<<ISBN<<endl;
	cout<<"enter the publisher"<<endl;
	cin>>publisher;enter<<publisher<<endl;
	enter.close();
}
void paper::Read(char *book_name){
	ifstream in (book_name);
	if(!in){
		cout<<"no this book"<<endl; 
		return ;
	}	
	while (!in.eof()){
	in.getline(show_content,500);
	cout<<show_content <<endl;	
	}
	in.close();
} 
//// 
int main() {
	UserManager myusermanager;
	//新建一个可以储存书名的文件
	ifstream booknames("booknames.txt");
	if(!booknames)
	{
		ofstream booknames("booknames.txt");
		cout<<"booknames is created"<<endl;
		booknames.close() ;
	}
	else 	booknames.close() ;
	//新建一个储存管理员信息的文件包括用户名和密码：admin123 
	ifstream admin("admin");
	if(!admin){
		ofstream admin("admin");
		cout<<"admin is created"<<endl;
		admin<<"admin"<<endl<<"admin123"<<endl<<"admin"<<endl;
		admin.close();
	} 
	else	admin.close();
	// 
	cout<<"if you are a new user,enter 0;if you want to log in,enter 1"<<endl;
	cin>>number;
	if(number==0)
	{
		cout<<"Please enter ID"<<endl;
		cin>>ID_name;
		ifstream in(ID_name);
		if(!in)	{
			myusermanager.createUser(ID_name);
		}
		else{
			cout<<"the user is created"<<endl;
		}
	}
	if(number==1){
		cout<<"Please enter your ID"<<endl;
		cin>>ID_name;
		ifstream in(ID_name);
		if(!in)
		{
			cout<<"no this user"<<endl;
			return 0;
		}
		cout<<"Please enter your password"<<endl;
		 char password_[50];cin>>password_;
		in.getline(SHOW,200);
		in.getline(SHOW,200);
		User myuser; 
		if(strcmp(SHOW,password_)==0){
			cout<<"PASS"<<endl;
			in.getline(SHOW,200);
			in.close();
			if(strcmp(SHOW,"admin")==0){							//管理员登陆 
				cout<<"welcome,admin"<<endl;
				cout<<"If you want to enter,choose 1;"<<endl;
				cout<<"If you want to update,choose 2;"<<endl;
				cout<<"If you want to delete book,choose 3;"<<endl;
				cout<<"If you want to delete user,choose 4"<<endl;
				cin>>number;
	switch(number){ 
		case 1:
			cout<<"Please the name of the book you want to enter in:"<<endl;
			cin>>book_name;
			cout<<"Please the typeof the book you want to enter in,电子书：1，实体书：0"<<endl;
			int type;
			cin>>type;
			if(type==1)			//电子书  
			{ 
				Book mybook(book_name);
				mybook.Enter(book_name);
			}
			else{
				paper mypaper(book_name);
				mypaper.Enter(book_name); 
			}	
			break;	
		case 2:
			cout<<"Please the name of the book you want to update:"<<endl;
			cin>>book_name;
			myuser.update(book_name);
			break;	
		case 3:
			cout<<"Please the name of the book you want to delete:"<<endl;
			cin>>book_name;
			myuser.Delete(book_name);
			break; 
		case 4:
			cout<<"Please the user youwant to delete"<<endl;
			cin>> ID_name;
			ifstream in(ID_name);
			if(!in){
				cout<<"the user not exsist"<<endl;
				return 0;
			}
			in.close();
			remove(ID_name);
			cout<<"the user is deleted"<<endl;
			break;
	}
			}
		else{													//用户登录 
				paper mypaper(book_name);
				cout<<"welcome,user"<<endl;
				cout<<"if you want to borrow,enter 1"<<endl;
				cout<<"if you want to return,enter 2"<<endl;
				cout<<"if you want to read,enter 3"<<endl;
				cout<<"if you want to search,enter 4"<<endl; 
				cin>>number;char Q[50];
	switch(number){
		case 1:
			cout<<"enter the book you want to borrow"<<endl;
			cin>>Q;
			//cout<<Q<<endl;cout<<ID_name<<endl;
			 myuser.Borrow(ID_name,Q);
			 break;
		case 2:
			cout<<"enter the book you want to borrow"<<endl;
			cin>>Q;
			 myuser.Return(ID_name,Q);
			 break;
		
		case 4:
			cout<<"enter the key"<<endl;
			cin>>Q;
			myuser.Search(Q);
			break;
		case 3:
			Book mybook(book_name);
			cout<<"enter the book you want to read"<<endl;
			cin>>Q;
			ifstream In(Q);
			if(!In ){
				cout<<"no this book"<<endl;
				return 0;
			}
			In.getline(SHOW,500);
			In.getline(SHOW,500);
			In.close();
			if(strcmp(SHOW,"type:1")==0){
				mybook.Read(Q);
			}
			else{
				mypaper.Read(Q);
			}
			break;	}
		}
	}
	else{
		cout<<"password is error"<<endl;
	}			
	return 0;
}
}

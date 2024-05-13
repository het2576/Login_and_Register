#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout<<"\t\t\t______________________________________________\n\n\n";
    cout<<"\t\t\t            Welcome to Login Page             \n\n\n";
    cout<<"\t\t\t_________________   MENU   ___________________\n\n";
    cout<<"                                                    \n\n";
    cout<<"\t| Press 1 to LOGIN                         |"<<endl;
    cout<<"\t| Press 2 to REGISTER                      |"<<endl;
    cout<<"\t| Press 3 to if you fogot your PASSWORD    |"<<endl;
    cout<<"\t| Press 4 to EXIT                          |"<<endl;
    cout<<"\n\t\t\t Please enter your choice  : ";
    cin>>c;
    cout<<endl;

    switch (c) 
    {
    case 1:
       login();
        break;
    case 2:
      registration();
        break;
    case 3:
       forgot();
        break;
    case 4:
       cout<<"\t\t\t Thankyou!  \n\n";
       break;
    default:
    system("cls");
        cout<<"\t\t\t Invalid Choice..\n\n"<<endl;
        main();
    }
    return 0;
}

    void login(){
        int count=0;
        string userId,password,id,pass;
        system("cls");
        cout<<"\t\t\t Please enter the username and password : "<<endl;
        cout<<"\t\t\t USERNAME : ";
        cin>>userId;
        cout<<"\t\t\t PASSWORD : ";
        cin>>password;

        ifstream input("records.txt");
        while (input>>id>>pass)
        {
            if(id==userId && pass==password){
                count=1;
                system("cls");
                break;
            }
        }
        input.close();

        if(count==1){
            cout<<userId<<"\n Your LOGIN is sucessfull \n Thanks for Logging in ! \n";
            main();
        }
         else {
            cout<<"\n Incorrecrt USERNAME or PASSWORD \n";
            main();
        }

    }

    void registration(){
        string r_userId,r_password,r_id,r_pass;
        system("cls");
        cout<<"\t\t\t Enter the Username : ";
        cin>>r_userId;
        cout<<"\t\t\t Enter the Password : ";
        cin>>r_password;

        ofstream f1("records.txt",ios::app);
        f1<<r_userId<<"   "<<r_password<<endl;
        system("cls");
        cout<<"\n\t\t\t Registration is Successfull ;) \n";
        main();
     }

     void forgot(){
        int option;
        system("cls");
        cout<<"\t\t\t You forgot your password ?? No worries\n";
        cout<<"Press 1 to search yout id by username "<<endl;
        cout<<"Press 2 to go back to the main menu "<<endl;
        cout<<"\t\t\t Enter your choice :";
        cin>>option;
        switch (option)
        {
        case 1:{
            int count=0;
            string s_userId,s_Id,s_pass;
            cout<<"\n\t\t\t Enter your username :";
            cin>>s_userId;

            ifstream f2("records.txt");
            while(f2>>s_Id>>s_pass){
                if(s_Id==s_userId){
                    count=1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n Your Account is found!\n";
                cout<<"\n\n Yout password is : "<<s_pass;
                main();
            }else{
                cout<<"\n\t Username not found!\n";
                main();
            }
        }
           break;

           case 2:{
            main();
           }      
        default:
            cout<<"\t\t\t Wrong choice ! Please try again "<<endl;
            forgot();
            break;
        }

     }

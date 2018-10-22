#include <iostream>
#include<string.h>
using namespace std;

class Customers{
 private:
    char name[30],acctype[20];
    int accno;
    float bal;
 public:
    Customers();
    void disp();
    void withdraw(Customers[],int);
    void deposit(Customers[],int);
    int HighestSal(Customers[],int n);
    void Update(Customers[],int);
};
Customers::Customers(){
    int i=0;
    while(i==0){
        cout<<"Enter the following\n1 Depositor Name\n2Account Type(NOTE:Type SB for saving bank account and CUR for current type account)\n3Account number\n4 Balance in Account"<<endl;
        cin>>name>>acctype>>accno>>bal;
        if(strcmp(acctype,"SB")==0||strcmp(acctype,"CUR")==0)
            i=1;
        else
            cout<<"Invaid Account Type.ReEnter the data"<<endl;
    }
}
void Customers::disp(){
    cout<<"Name\t\tAccType\t\tAccNo.\t\tBalance"<<endl;
    cout<<name<<"\t\t"<<acctype<<"\t\t"<<accno<<"\t\t"<<bal<<endl;
}
void Customers::withdraw(Customers cs[],int n){
    char name1[30];
    int i;
    float wdraw;
    cout<<"Enter the customer name\n"<<endl;
    cin>>name1;
    for(i=0;i<n;i++){
        if(strcmp(name1,cs[i].name)==0){
            cout<<"Enter the withdrawing amount"<<endl;
            cin>>wdraw;
            if((strcmp(cs[i].acctype,"SB")==0)&&(cs[i].bal-wdraw>500)){
                cs[i].bal-=wdraw;
                cout<<"Transaction Succesfull"<<endl;
            }
            else if((strcmp(cs[i].acctype,"CUR")==0)&&(cs[i].bal-wdraw>100)){
                cs[i].bal-=wdraw;
                cout<<"Transaction Succesfull"<<endl;
                return;
            }
            else
                cout<<"Insufficient funds"<<endl;
            cs[i].disp();
            return;
        }
    }
    cout<<"Invalid customer name"<<endl;
}
void Customers::deposit(Customers cs[],int n){
    char name1[30];
    float depo;
    int i;
    cout<<"Enter the customer name"<<endl;
    cin>>name1;
    for(i=0;i<n;i++){
        if(strcmp(name1,cs[i].name)==0){
            cout<<"Enter the deposit amount"<<endl;
            cin>>depo;
            cs[i].bal+=depo;
            cout<<"Transaction successful"<<endl;
            cs[i].disp();
            return;
        }
    }
    cout<<"Invalid customer name"<<endl;
}
int Customers::HighestSal(Customers cs[],int n){
    int i,c;
    float temp;
    temp=cs[0].bal;
    for(i=0;i<n;i++){
        if(temp<cs[i].bal){
            temp=cs[i].bal;
            c=i;
        }
    }
    return c;
}
void Customers::Update(Customers cs[],int n){
    int acc,i,choice;
    cout<<"Enter the account number to be updated"<<endl;
    cin>>acc;
    for(i=0;i<n;i++){
        if(cs[i].accno==acc){
            for(;;){
                cout<<"Enter your choice to update\n1 Name\n2 Account Type\n3 Account Number\n4 Balance\n5 Exit"<<endl;
                cin>>choice;
                switch(choice){
                case 1:
                    cout<<"Enter the name to be updated"<<endl;
                    cin>>cs[i].name;
                    break;
                case 2:
                    cout<<"Enter the Account Type to be updated"<<endl;
                    cin>>cs[i].acctype;
                    break;
                case 3:
                    cout<<"Enter the Account Number to be updated"<<endl;
                    cin>>cs[i].accno;
                    break;
                case 4:
                    cout<<"Enter the Balance to be updated"<<endl;
                    cin>>cs[i].bal;
                    break;
                case 5:
                    cout<<"Updated info of the customer"<<endl;
                    cs[i].disp();
                    return;
                }
            }
        }
    }
    cout<<"Invalid Account Number"<<endl;
}

int main()
{
    int n,i,choice;
    cout<<"Enter the numbers of customers of the bank"<<endl;
    cin>>n;
    Customers cs[n];
    for(;;){
        cout<<"Enter your choice\n1 WithDraw\n2 Deposit\n3 Highest balance maintaining customers\n4 Update the customers info\n5 Exit"<<endl;
        cin>>choice;
        switch(choice){
         case 1:
            cs[0].withdraw(cs,n);
            break;
         case 2:
            cs[0].deposit(cs,n);
            break;
         case 3:
            cs[cs[0].HighestSal(cs,n)].disp();
            break;
         case 4:
            cs[0].Update(cs,n);
            break;
         case 5:
            for(i=0;i<n;i++)
                cs[i].disp();
            return 0;
        }
    }
    return 0;
}

#include <iostream>//HOw to input space//cin.getline(name,30)//getline(cin,name)//Testing Git
#include <string.h>
using namespace std;

class Book{
private:
    char name[30],code[30];
    float cost;
    int quan;
public:
    static int s,us;
    Book();
    void disp();
    void transaction(Book bk[],int n);
    void Update(Book bk[],int n);
};
int Book::s=0;
int Book::us=0;
Book::Book(){
    cout<<"Enter the name,code,cost per unit and quantity of books"<<endl;
    cin>>name>>code>>cost>>quan;
}
void Book::disp(){
    cout<<"NAME\t"<<"CODE\t"<<"COST\t"<<"QUANTITY\t"<<endl;
    cout<<name<<"\t"<<code<<"\t"<<cost*quan<<"\t"<<quan<<endl;
    }
void Book::transaction(Book bk[],int n){
    int i;
    char ucode[30];
    cout<<"Enter the book code"<<endl;
    cin>>ucode;
    for(i=0;i<n;i++){
        if(strcmp(ucode,bk[i].code)==0){
            cout<<"Enter the number of copies"<<endl;
            cin>>bk[i].quan;
            bk[i].disp();
            s++;
            return;
        }
    }
    cout<<"Invalid code!Try Again"<<endl;
    us++;
}
void Book::Update(Book bk[],int n){
    int i,choice;
    char ucode[30];
    cout<<"Enter the book code to be updated"<<endl;
    cin>>ucode;
    for(i=0;i<n;i++){
        if(strcmp(ucode,bk[i].code)==0){
            for(;;){
                cout<<"Enter your choice\n1 Name\n2 Code\n3 Per unit price\n4 Quantity\n5 Exit"<<endl;
                cin>>choice;
                switch(choice){
                    case 1:
                        cout<<"Enter the name to updated"<<endl;
                        cin>>bk[i].name;
                        break;
                    case 2:
                        cout<<"Enter the code to be updated"<<endl;
                        cin>>bk[i].code;
                        break;
                    case 3:
                        cout<<"Enter the per unit cost to be updated"<<endl;
                        cin>>bk[i].cost;
                        break;
                    case 4:
                        cout<<"Enter the number of quantities to be updated"<<endl;
                        cin>>bk[i].quan;
                        break;
                    case 5:
                        cout<<"The updated book info is"<<endl;
                        bk[i].disp();
                        return;
                }
            }
        }
    }
    cout<<"Invalid code!Try Again"<<endl;
}

int main()
{
    int n,choice;
    cout<<"Enter the number of books"<<endl;
    cin>>n;
    Book bk[n];
    for(;;){
        cout<<"Enter your choice\n1 To buy the book\n2 Display number of succesfull and unsuccesfull transaction\n3 Update the book info\n4 Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                bk[0].transaction(bk,n);
                break;
            case 2:
                cout<<"Number of successfull transaction is "<<Book::s<<"\nNumber of unsuccessfull transaction is "<<Book::us<<endl;
                break;
            case 3:
                bk[0].Update(bk,n);
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}




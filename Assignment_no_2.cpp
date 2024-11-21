/*BOOK SHOP:Inventary of Books to be sold*/

#include<iostream>
#include<string.h>//to use strcpy and strcmp
using namespace std;

int n;//To get number of books to be stored from user.
int i;//Iterative variable

//class with name books
class books{
    public:
    int price,sp;
    char *tt,*aut,*pub;
    
    //Constructor
    books(){
        tt=new char;//
        aut=new char;
        pub=new char;
        price=100;
        sp=10;
        strcpy(tt,"oop");
        strcpy(aut,"aa");
        strcpy(pub,"ttt");
    }
    void accept();//To get data from user
    void display();//to display all data about books
    void search();//To search the book to be sold
    
    //Destructor
    ~books(){
        cout<<"Destructor is called"<<endl;
    }
}b[10];//array of 10 objects

void books::accept()
{
    cout<<"Enter Book title: ";
    cin>>tt;
    cout<<"Enter Author name: ";
    cin>>aut;
    cout<<"Enter price: ";
    cin>>price;
    cout<<"Enter publisher name : ";
    cin>>pub;
    cout<<"Enter stock position: ";
    cin>>sp;
}

void books::display()
{
    cout<<tt<<"\t"<<aut<<"\t"<<pub<<"\t"<<price<<endl;
}

void books::search()
{
    int cost;//to display total cost if book is available
    int f=0,f1=0;//f=1 indicate book found and f1=1 for copies available 
    char *t,*a;//to get title and author name for searching the book
    int cp;//to get number of copies to be purchased from user
    t=new char;
    a=new char;
    cout<<"\nEnter the book details you want to search: \n";
    cout<<"Title: ";
    cin>>t;
    cout<<"Author: ";
    cin>>a;
    
    //Search the book 
    for(i=0;i<n;i++)
    {
        if(strcmp(t,b[i].tt)==0 && strcmp(a,b[i].aut)==0)
        {
            f=1;
            cout<<"Book available.\n";
            cout<<"Title\tAuthor\tPublisher\tPrice\n";
            b[i].display();
            
            cout<<"Enter the nuber of copies to be purchased: ";
            cin>>cp;
            if(cp<=b[i].sp)
            {
                f1=1;
                cost=b[i].price*cp;
                cout<<"Total cost= "<<cost<<endl;
                break;
            }
        }
    }
    
    if(f==1 && f1==0)
    {
    cout<<"\n Book is availble but number of copies are not avialble";
    }

    if(f==0)
    {
        cout<<"\n Book is not found";
    }
}


int main(){
    cout<<"\nEnter the number of books you want to store: ";
    cin>>n;
    int ch;//to get choice for menu operation from user
    
    do{
        cout<<"\nMENU\n";
        cout<<"1. Accept\n2. Dispaly\n3. Search\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:    for(i=0;i<n;i++)
                        {
                            cout<<"\nEnter book "<<i<<" details:\n";
                            b[i].accept();
                        }
            break;
            case 2:cout<<"Title\tAuthor\tPublisher\tPrice\n";
                    for(i=0;i<n;i++)
                    {
                        b[i].display();
                    }
            break;
            case 3:b[i].search();
            break;
            default:cout<<"\ninvalid choice\n";
            
        }
    }while(ch!=4);
    
    
    return 0;
}

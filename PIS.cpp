#include<iostream>
#include<cstring>
using namespace std;

int i, n;

class PIS
{
	static int cnt;
	public: 
	int pn, ht, wt;
	char *name, *dln, *add;
	
   public:
   	PIS()
   	{
   	  pn = 100;
   	  ht = 165;
   	  wt = 70;
   	  
   	  name = new char;
   	  dln = new char;
   	  add = new char;
   	  
   	  strcpy(dln,"ln 100");
   	  strcpy(name,"VVV");
   	  strcpy(add,"Nashik");
   	}
   	
   	PIS(int h, int w)
   	{
   	  ht = h;
   	  wt = w;
   	}
   	
   	PIS(PIS &ss)
   	{
   	  ht = ss.ht;
   	  wt = ss.wt;
   	}
   	
   	
   void accept()
   {
   	cnt++;
   	cout<<"\nEnter the name: ";
	cin>>name;
	cout<<"Enter the address: ";
	cin>>add;
	cout<<"Enter the Driving L No.: ";
	cin>>dln;
	cout<<"Enter the height: ";
	cin>>ht;
	cout<<"Enter the weight: ";
	cin>>wt;
	cout<<"Enter the pn: ";
	cin>>pn;
   }
   
   void display();
   
  ~PIS()
  {
    delete name;
    delete add;
    delete dln;
    cout<<"\nDestructor is called.\n";
  }
  
  static void discnt()
  {
     cout<<"\n\nTotal record in database is "<<cnt;
  }
  
  friend void search(PIS s);

}s[100];


int PIS::cnt;

void search(PIS s[])
{
  int p,f=0;
  cout<<"\n\nEnter the PN: ";
  cin>>p;
  for(int i=0;i<100;i++)
  {
  if(p==s[i].pn)
 { 
    f=1;
    break;
  }
  }
    if(f == 1)
  {
     cout<<"\nFound";
  }
  else
  {
     cout<<"\nNot Found";
  }
}

inline void PIS::display()
{
  
   cout<<"\n"<<name<<"\t"<<add<<"\t"<<dln<<"\t"<<ht<<"\t"<<wt<<"\t"<<pn;
}

int main()
{
    int choice=1;

    while(choice != 5)
    {
        cout << "\n\nMenu.\n1.Accept the record.\n2.Display the record.\n3.count record.\n4.Search Record.\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter the number of records you want to create: ";
            cin >> n;
            for(i = 0; i < n; i++)
            {
                s[i].accept();
            }
            break;

        case 2:
            cout << "\nName\tadd\tdln\tht\twt\tpn";
            for(i = 0; i < n; i++)
            {
                s[i].display();
            }
            break;
            
        case 3:
        	PIS::discnt();
        	break;
        	
        case 4:
        	search(s);
        	break;
        	
        case 5:
        	
            	choice=5;
            	break;

            default:
                cout << "Invalid choice\n";
                break;
            
            }
    }

    return 0;
}

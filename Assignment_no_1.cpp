#include <iostream>
#include <string>
using namespace std;

int n = 10;

class MyBank {
public:
    int accno, amt, damt, wamt;
    string name;
    void accept();
    void display();
    void deposit();
    void withdraw();
    MyBank() {
        accno = 100;
        amt = 1000;
        name = "MyBank";
    }
} b[10];

void MyBank::accept() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter amount: ";
    cin >> amt;
    cout << "Enter account number: ";
    cin >> accno;
}

void MyBank::display() {
    cout << "\nName=" << name << "\nAccount No.=" << accno << "\nAmount=" << amt << endl;
}

void MyBank::deposit() {
    int ac;
    cout << "Enter your account number: ";
    cin >> ac;
    for (int i = 0; i < n; i++) {
        if (b[i].accno == ac) {
            cout << "Enter the amount to be deposited: ";
            cin >> damt;
            b[i].amt += damt;
            cout << "Amount deposited successfully\n";
            cout << "Your current balance is: " << b[i].amt << endl;
            return;
        }
    }
    cout << "Account not found" << endl;
}

void MyBank::withdraw() {
    int ac;
    cout << "Enter your account number: ";
    cin >> ac;
    for (int i = 0; i < n; i++) {
        if (b[i].accno == ac) {
            cout << "Your current balance is: " << b[i].amt << endl;
            cout << "Enter the amount to be withdrawn: ";
            cin >> wamt;
            if (wamt <= b[i].amt) {
                b[i].amt -= wamt;
                cout << "Withdrawal successful. Your current balance is: " << b[i].amt << endl;
            } else {
                cout << "Entered amount is more than your current balance.\n";
            }
            return;
        }
    }
    cout << "Account not found" << endl;
}

int main() {
    cout << "Enter the number of accounts to be opened: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter account " << i + 1 << " details: \n";
        b[i].accept();
    }
    
    int ch, ac;
    do {
        cout << "\nMenu Operations: \n";
        cout << "1. Check Status\n2. Deposit Amount\n3. Withdraw Amount\n4. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter your account number: ";
            cin >> ac;
            for (int i = 0; i < n; i++) {
                if (b[i].accno == ac) {
                    b[i].display();
                    break;
                }
            }
            break;
        case 2:
            b[0].deposit();
            break;
        case 3:
            b[0].withdraw();
            break;
        case 4:
            cout << "Exit Successful\n";
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (ch != 4);

    return 0;
}

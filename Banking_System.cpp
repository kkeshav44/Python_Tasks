// KESHAV THAKUR 
 
#include <iostream> 
#include <string> 
using namespace std; 
 
// Transaction class 
class Transaction { 
public: 
    string type;    // deposit, withdrawal, transfer 
    float amount; 
    string note; 
 
    void display() { 
        cout << type << " of ₹" << amount << " | " << note << endl; 
    } 
}; 
 
// Account class 
class Account { 
public: 
    int accountNumber; 
    float balance; 
    Transaction transactions[100]; 
    int transactionCount; 
 
    Account() { 
        accountNumber = 0; 
        balance = 0; 
        transactionCount = 0; 
    } 
 
    void deposit(float amount, string note = "Self deposit") { 
        balance += amount; 
        transactions[transactionCount++] = {"Deposit", amount, note}; 
        cout << "₹" << amount << " deposited successfully.\n"; 
    } 
 
    void withdraw(float amount, string note = "Self withdrawal") { 
        if (amount > balance) { 
            cout << "Not enough balance.\n"; 
            return; 
        } 
        balance -= amount; 
        transactions[transactionCount++] = {"Withdrawal", amount, note}; 
        cout << " ₹" << amount << " withdrawn successfully.\n"; 
    } 
 
    void transfer(Account &receiver, float amount) { 
        if (amount > balance) { 
            cout << "Not enough balance to transfer.\n"; 
            return; 
        } 
        balance -= amount; 
        receiver.balance += amount; 
 
        transactions[transactionCount++] = {"Transfer to " + to_string(receiver.accountNumber), 
amount, "Sent"}; 
        receiver.transactions[receiver.transactionCount++] = {"Transfer from " + 
to_string(accountNumber), amount, "Received"}; 
 
        cout << "₹" << amount << " transferred to Account " << receiver.accountNumber << ".\n"; 
    } 
 
    void showBalance() { 
        cout << "Current balance: ₹" << balance << endl; 
    } 
 
    void showTransactions() { 
        cout << "\nTransaction History for Account " << accountNumber << ":\n"; 
        if (transactionCount == 0) { 
            cout << "No transactions yet.\n"; 
        } else { 
            for (int i = 0; i < transactionCount; i++) { 
                transactions[i].display(); 
            } 
        } 
    } 
}; 
 
// Customer class 
class Customer { 
public: 
    string name; 
    Account account; 
 
    void createCustomer(string customerName, int accNumber) { 
        name = customerName; 
        account.accountNumber = accNumber; 
        cout << "Customer " << name << " created with Account No: " << accNumber << endl; 
    } 
 
    void showInfo() { 
        cout << "\n Customer: " << name << endl; 
        cout << "Account No: " << account.accountNumber << endl; 
        account.showBalance(); 
    } 
}; 
 
int main() { 
    Customer customer1, customer2; 
 
     
    customer1.createCustomer("KESHAV", 79845); 
    customer2.createCustomer("MAYUR", 76000); 
 
    customer1.account.deposit(5000); 
    customer1.account.withdraw(1200); 
    customer1.account.transfer(customer2.account, 1500); 
 
 
    customer1.showInfo(); 
    customer1.account.showTransactions(); 
 
    customer2.showInfo(); 
    customer2.account.showTransactions(); 
 
    return 0; 
}
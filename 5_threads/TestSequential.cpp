#include <iostream>
#include <string>

int bank_balance = 300;

void withdraw(const std::string& msg, int amount) {
   int bal = bank_balance;
   std::string out_string = msg + " withdraws " + std::to_string(amount) + "\n";
   std::cout << out_string;
   bank_balance = bal - amount;
}

int main() {
   std::cout << "Starting balance is " << bank_balance << "\n";
   withdraw("Jean", 100);
   withdraw("Jade", 100);
   std::cout << "Final bank balance is " << bank_balance << "\n";

   return 0;
}

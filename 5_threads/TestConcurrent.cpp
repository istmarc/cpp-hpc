#include <iostream>
#include <string>
#include <thread>

int bank_balance = 300;

void withdraw(const std::string& msg, int amount) {
   int bal = bank_balance;
   std::string out_string = msg + " withdraws " + std::to_string(amount) + "\n";
   std::cout << out_string;
   bank_balance = bal - amount;
}

int main() {
   std::cout << "Starting balance is " << bank_balance << "\n";
   std::thread jean(withdraw, "Jean", 100);
   std::thread jade(withdraw, "Jade", 100);
   jean.join();
   jade.join();
   std::cout << "Final bank balance is " << bank_balance << "\n";

   return 0;
}

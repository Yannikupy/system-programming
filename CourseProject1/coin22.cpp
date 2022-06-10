/*  BYA   */
#include "mlisp.h"
double largest/*1*/ (double coins__set);
	double count__change/*12*/ (double amount);
	bool Shaeffer_Q/*26*/ (double x_Q, double y_Q);
	 double cc/*30*/ (double amount, double coins__set);
	double denomination__list/*38*/ (double coins__set);
	extern double VARIANT/*45*/;
	extern double COINS/*46*/;
	//________________ 
double largest/*1*/ (double coins__set){
 return
 ((coins__set == 1.) 
	? 1. 
	 :(coins__set == 2.) 
	? 2. 
	 :(coins__set == 3.) 
	? 3. 
	 :(coins__set == 4.) 
	? 25. 
	 :(coins__set == 5.) 
	? 50. 
	 :true 
	? 0.
	 : _infinity);
	 }
double count__change/*12*/ (double amount){
 display("______");
	 newline();
	 display(" amount: ");
	 display(amount);
	 newline();
	 display("COINS: ");
	 display(COINS);
	 newline();
	 return
 (((0. > amount) || (0. == amount) || (1. > COINS) || (largest(COINS) == 0.)) 
	? display("Improper parameter value!"),
	 newline(),
	 display("count-change= "),
	 -1. 
	 :true 
	? display("List of coin denominations: "),
	 denomination__list(COINS),
	 display("count-change= "),
	 cc(amount, COINS)
	 : _infinity);
	 }
bool Shaeffer_Q/*26*/ (double x_Q, double y_Q){
 return
 (!(x_Q) || !(y_Q));
	 }
double cc/*30*/ (double amount, double coins__set){
 return
 ((amount == 0.) 
	? 1. 
	 :Shaeffer_Q(((amount > 1.) || (amount == 1.)),  (coins__set > 0.)) 
	? 0. 
	 :true 
	? (cc(amount, (coins__set - 1.)) + cc((amount - largest(coins__set)), coins__set))
	 : _infinity);
	 }
double denomination__list/*38*/ (double coins__set){
 return
 ((coins__set == 0.) 
	? newline(),
	 0. 
	 :true 
	? display(largest(coins__set)),
	 display(" "),
	 denomination__list((coins__set - 1.))
	 : _infinity);
	 }
double VARIANT/*45*/ = 2.;
	double COINS/*46*/ = 5.;
	int main(){
display("Variant ");
	 display(VARIANT);
	 newline();
	 display(count__change(100.));
	 newline();
	 COINS = 13.;
	 display(count__change(100.));
	 newline();
	 display("(c) Yan Borisov 2022");
	 newline();
	 std::cin.get();
 return 0;
}


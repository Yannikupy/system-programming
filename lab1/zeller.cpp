//zeller.cpp
#include "mlisp.h"
double day__of__week();
double zeller(double d, double m, double y, double c);
double neg__to__pos(double d);
double birthday(double dw);
extern double dd;
extern double mm;
extern double yyyy;

//(define (day-of-week)
// (zeller dd
//      (+ 8(if(<= mm 2)(+ mm 2) (- mm 010)))
//      (remainder (+ 1(cond((< mm 3)(- yyyy 2))(else (- yyyy 1))))
//                 100)
//      (quotient (cond((>= 2 mm)(- yyyy 1))(#t yyyy))
//                100)
// )
//)

double day__of__week(){
    return (zeller(dd, 8 + (mm <= 2 ? mm + 2 : mm - 10),
                   remainder(1 + (mm < 3 ? yyyy - 2 : yyyy - 1), 100),
                   quotient((2 >= mm ? yyyy - 1 : true ? yyyy : _infinity), 100)));
}

// (define (zeller d m y c)
//  (neg-to-pos (remainder (+ d y
//                           (quotient (-(* 26 m)2) 10)
//                           (quotient y 4)
//                           (quotient c 4)
//                           (* 2(- c))
//                        )
//             7)
//  )
// )

double zeller(double d, double m, double y, double c){
    return neg__to__pos(remainder((d + y + quotient(26. * m - 2., 10.) + quotient(y, 4.) + quotient(c, 4.) - 2. * c), 7.));
}

//...
//(define (neg-to-pos d)
// (cond((< d 0)(+ d 7))
//      (#t d)
// )
//)

double neg__to__pos(double d){
 return (d < 0. ? d + 7.
         : true ? d
         : _infinity
        );
}

//(define (birthday dw)
//;                  ^{0,...,6}
// (display "Yan Borisov was born on ")
//    (display
//     (cond
//          ((= dw 0)"Sunday ")
//          ((= dw 1)"Monday ")
//          ((= dw 2)"Tuesday ")
//          ((= dw 3)"Wednesday ")
//          ((= dw 4)"Thursday ")
//          ((= dw 5)"Friday ")
//          (else "Saturday ")
//     ))
//  (display dd)(display ".")
//  (display mm)(display ".")
// yyyy
//)

double birthday(double dw){
  display("Yan Borisov was born on ");
  display((dw == 1.   ? "Monday "
              : dw == 2. ? "Tuesday "
              : dw == 3. ? "Wednesday "
              : dw == 4. ? "Thursday "
              : dw == 5. ? "Friday "
              : dw == 6. ? "Saturday "
              : "Sunday "));
  display(dd);
  display(".");
  display(mm);
  display(".");
  return yyyy;
}

double dd = 26.;
double mm = 6.;
double yyyy = 2002.;

int main(){
  display(birthday (day__of__week()));
  newline();
  std::cin.get();
  return 0;
}

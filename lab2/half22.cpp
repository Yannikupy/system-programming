//zeller.cpp
#include "mlisp.h"

double root(double a, double b);
double half__interval(double a, double b, double fa, double fb);
double __BYA__try(double neg__point, double pos__point);
bool close__enough_Q(double x, double y);
double average (double x, double y);
double f(double z);
extern double total__iterations;
extern double tolerance;


//(define (root a b)
// (define temp 0)
// (set! temp (half-interval a b (f a)(f b)))
//  (display"Total number of iteranions=")
//  (display total-iterations)(newline)
// (display"[")
// (display a)
// (display" , ")
// (display b)
// (display"]")
//      temp
//)

double root(double a, double b){
    double temp = 0.;
    temp = half__interval(a, b, f(a), f(b));
    display("Total number of iterations=");
    display(total__iterations); newline();
    display("[");
    display(a);
    display(" , ");
    display(b);
    display("]");
    return temp;
}

//(define (half-interval a b fa fb)
// (define root 0)
// (set! total-iterations 0)
//   (set! root(cond((and(< fa 0)(> fb 0))
//                 (try a b))
//         ((and(> fa 0)(< fb 0))
//                 (try b a))
//         (else(+ b 1)))
//    )
//  (newline)
//  root
//)

double half__interval(double a, double b, double fa, double fb){
    double root = 0.;
    total__iterations = 0.;
    root = (fa < 0. && fb > 0.) ? __BYA__try(a, b) : ((fa > 0. && fb < 0.) ? __BYA__try(b, a) : b + 1.);
    newline();
    return root;
}

//(define (average x y)(*(+ x y)(/ (* 2.0))))

double average(double x, double y){
    return (x + y) * (1. / 2.);
}

//(define(try neg-point pos-point)
// (define midpoint 0)
// (define test-value 0)
//     (set! midpoint (average neg-point pos-point))
//     (cond((close-enough? neg-point pos-point) midpoint)
//          (else (set! test-value (f midpoint))
//               (display "+")
//               (set! total-iterations (+ total-iterations 1))
//               (cond((> test-value 0)(try neg-point midpoint))
//                    ((< test-value 0)(try midpoint pos-point))
//                    (else midpoint))
//          )
//     )
//)

double __BYA__try(double neg__point, double pos__point){
    double midpoint = 0.;
    double test__value = 0.;
    midpoint = average(neg__point, pos__point);
    return (close__enough_Q(neg__point, pos__point) ? midpoint : (test__value = f(midpoint), display("+"), total__iterations = total__iterations + 1., test__value > 0. ? __BYA__try(neg__point, midpoint) : (test__value < 0. ? __BYA__try(midpoint, pos__point) : midpoint)));

}

//(define (close-enough? x y)
//  (<(abs (- x y))tolerance))

bool close__enough_Q(double x, double y){
    return (abs(x - y) < tolerance);
}

double tolerance = 0.001;
double total__iterations = 0.;

//(define(f z)
//  (- (abs (- (+ (* 3 z) (exp z)) (exp (- z)))) 4)
//)

double f(double z){
    return abs(3. * z + exp(z) - exp(-z)) - 4.;
}

int main(){
    display("Variant 208-02\n");
    display(root(0.0, 1.));
    newline();
    display("(c) Yan Borisov 2022\n");
    newline();
    std::cin.get();
    return 0;
}

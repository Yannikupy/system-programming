
(define (day-of-week)
 (zeller dd
      (+ 8(cond((or (> 2 mm) (= mm 2))(+ mm 2)) (#t(- mm 010))))
      (remainder (+ 1(cond((> 3 mm)(- yyyy 2))(#t (- yyyy 1))))
                 100)
      (quotient (cond((or (> 2 mm) (= mm 2))(- yyyy 1))(#t yyyy))
                100)
 )
)
(define (zeller d m y c)
 (neg-to-pos (remainder (+ d y
                          (quotient (-(* 26 m)2) 10)
                          (quotient y 4)
                          (quotient c 4)
                          (* 2(- c))
                       )
            7)
 )
)
(define (neg-to-pos d)
 (cond((> 0 d)(+ d 7))
      (#t d)
 )
)
(define (birthday dw)
                 
 (display "Yan Borisov was born on ")
    (display
     (if (= dw 0)"Sunday "
         (if (= dw 1)"Monday "
             (if (= dw 2)"Tuesday "
                 (if (= dw 3)"Wednesday "
                     (if (= dw 4)"Thursday "
                         (if (= dw 5)"Friday " "Saturday"))))))
   
     )
  (display dd)(display ".")
  (display mm)(display ".")
 yyyy
)
(define dd 26)
(define mm 06)
(define yyyy 2002)
(birthday (day-of-week))

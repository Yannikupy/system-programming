(define (largest coins-set)
  (cond
          ((= coins-set 1) 1)
          ((= coins-set 2) 2)
          ((= coins-set 3) 3)
          ((= coins-set 4) 25)
          ((= coins-set 5) 50)
          (#t 0)
     )
)

(define (count-change amount)
  (display "______") (newline) (display " amount: ")
  (display amount)
      (newline)
  (display "COINS: ")
  (display COINS)
      (newline)
  (cond
         ((or (> 0 amount) (= 0 amount) (> 1 COINS) (= (largest COINS) 0)) (display "Improper parameter value!") (newline) (display "count-change= ") -1)
         (#t (display "List of coin denominations: ") (denomination-list COINS) (display "count-change= ") (cc amount COINS))
  )
)


(define (Shaeffer? x? y?)
  (or (not x?) (not y?))
)

(define (cc amount coins-set)
  (cond
    ((= amount 0) 1)
    ((Shaeffer? (or (> amount 1) (= amount 1)) (> coins-set 0)) 0)
    (#t (+ (cc amount (- coins-set 1)) (cc (- amount (largest coins-set)) coins-set)))
  )
)

(define (denomination-list coins-set)
  (cond
    ((= coins-set 0) (newline) 0)
    (#t (display (largest coins-set)) (display " ") (denomination-list (- coins-set 1)))
   )
)

(define VARIANT 2)
(define COINS 5)
(display "Variant ")
(display VARIANT)
(newline)
(display (count-change 100))(newline)
(set! COINS 13)
(display (count-change 100))(newline)
(display "(c) Yan Borisov 2022")
(newline)
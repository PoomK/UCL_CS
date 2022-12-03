fib 0 = 0
fib 1 = 1
fib n = fib(n-1) + fib(n-2)

qsort :: [Int] -> [Int]
qsort [] = []
qsort (x:xs) = qsort [a | a <- xs, a <= x] ++ [x] ++ qsort [b | b <- xs, b > x]

insert :: Int -> [Int] -> [Int]
insert n [] = [n]
insert n (x:xs) = if n <= x then n:x:xs else x : insert n (xs)


import Data.Char 
import Data.List

--square 
square :: Int -> Int
square n = n * n

-- pyth
pyth :: Int -> Int -> Int
pyth x y = (square x) + (square y)

-- isTriple
isTriple :: Int -> Int -> Int -> Bool
isTriple x y z = (pyth x y) == (square z)

-- isTripleAny
isTripleAny :: Int -> Int -> Int -> Bool
isTripleAny x y z = (isTriple x y z) || (isTriple x z y) || (isTriple z y x)

-- halveEvens halveEvens :: [Int] -> [Int]
halveEvens xs = [if x `mod` 2 == 0 then x `div` 2 else x | x <- xs]

-- inRange
inRange :: Int -> Int -> [Int] -> [Int]
inRange lo hi xs = [x | x <- xs, lo <= x, x <= hi]

-- countPositives
countPositives :: [Int] -> Int
countPositives list = length [x | x <- list, x > 0]

-- capitalised
capitalised :: String -> String
capitalised [] = []
capitalised (x:xs) = toUpper x : [toLower x | x <- xs]

-- title
-- auxiliary functions 
capitaliseLong :: String -> String
capitaliseLong word = if (length word >= 4) then (capitalised word) else (lowercase word)

lowercase :: String -> String
lowercase xs = [toLower x | x <- xs]

title :: [String] -> [String]
title [] = []
title (w:words) = capitalised w : [capitaliseLong w | w <- words]
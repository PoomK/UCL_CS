-- LabSheet2-solns.hs

import Data.Char
import Data.List

inRange :: Int -> Int -> [Int] -> [Int]
inRange n m [ ] = [ ]
inRange n m (x : xs) | (n <= x) && (x <= m) = x : (inRange n m xs)
                     | otherwise = inRange n m xs

countPositives :: [Int] -> Int
countPositives [ ] = 0
countPositives (x : xs) | x > 0 = 1 + (countPositives xs)
                        | otherwise = countPositives xs

-- Need an auxiliary function to handle treating the first letter differently. could use "where" clause instead of a separate function definition

auxCap :: [Char] -> [Char]
auxCap [ ] = [ ]
auxCap (x : xs) = toLower x : auxCap xs

capitalised :: [Char] -> [Char]
capitalised [ ] = [ ]
capitalised (x : xs) = (toUpper x) : (auxCap xs)

-- Again need an auxiliary function as the first word is treated differently to the subsequent ones and some words are handled differently to others

capLong :: [Char] -> [Char]
capLong [ ] = [ ]
capLong word | length word < 5 = word
             | otherwise = capitalised word

title :: [[Char]] -> [[Char]]
title [ ] = [ ]
title (w : words) = (capitalised w) : ( titleAux words)
    where titleAux [ ] = [ ]
          titleAux (w : words) = (capLong w) : (titleAux words)

isort :: Ord a => [a] -> [a]
isort [] = []
isort (x:xs) = insert' x (isort xs)
   where insert' x [] = [x]
         insert' x (y : ys) = if x <= y then x : (y : ys) else y : (insert' x ys)

merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge [] xs = xs
merge xs [] = xs
merge (x:xs) (y:ys) | x <= y = x:(merge xs (y:ys))
                    | otherwise = y:(merge (x:xs) ys)

-- rotor
rotor :: Int -> [Char] -> [Char]
rotor n [] = []
rotor 0 str = str
rotor n (c:str) | (0 <= n) && (n < length (c:str)) = rotor (n-1) (str ++ [c])
                | otherwise = error "offset out of range"

-- makeKey
makeKey :: Int -> [(Char,Char)]
makeKey n = zip upperAl (rotor n upperAl)
                where upperAl = ['A'..'Z']

-- lookUp

lookUp :: Char -> [(Char,Char)] -> Char
lookUp c [] = c
lookUp c ((c1,c2):pairs) | c == c1 = c2
                         | otherwise = lookUp c pairs

-- encipher
encipher :: Int -> Char -> Char
encipher n c = lookUp c (makeKey n)

-- normalise
normalise :: String -> String
normalise [] = []
normalise (c:str) | (c `elem` ['A'..'Z']) || (c `elem` ['0'..'9']) = c:(normalise str)
                  | (c `elem` ['a'..'z']) = (toUpper c) : (normalise str)
                  | otherwise = normalise str


-- encipherStr
encipherStr :: Int -> String -> String
encipherStr n str = encipherStrAux n (normalise str)
   where encipherStrAux n [] = []
         encipherStrAux n (c:str) = (encipher n c) : (encipherStrAux n str)
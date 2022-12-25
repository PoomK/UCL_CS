-- question 1.
sqList :: [Integer] -> [Integer]
sqList  = map (\x -> x*x) 

sumSqList :: [Integer] -> Integer
sumSqList = foldr (+) 0 . sqList

posList :: [Integer] -> Bool
posList = foldr (&&) True . map (>0)

-- question 2.

fMin :: Ord a => (Integer -> a) -> Integer -> a
fMin f n = minimum $ map f [0..n]

eqF :: Eq a => (Integer -> a) -> Integer -> Bool
eqF f n = foldr (&&) True $  map ((== f(0)) . f) [0..n]

posF :: (Num a, Ord a) => (Integer -> a) -> Integer -> Bool
posF f n = foldr (&&) True $ map ((> 0) . f) [0..n]

incOrd :: Ord a => [a] -> Bool
incOrd xs = foldr (&&) True $ map (\(x,y) -> x <= y) $ zip xs (tail xs)

-- question 3.

twice :: (a -> a) -> a -> a
twice f x = f $ f x

-- twice f = f . f {- pointless -}

-- question 4.

iter :: Integer -> (a -> a) -> a -> a
iter 0 f x = x
iter n f x = iter (n-1) f $ f x 

-- iterAcc :: Integer -> (a -> a) -> (a -> a) -> a -> a
-- iterAcc 0 f g = g
-- iterAcc n f g = iterAcc (n-1) f (f.g)
-- iter n f = iterAcc n f id  {- pointless -}

-- question 5.

double :: Integer -> Integer
double n = 2*n

-- double = (*2) {- pointless-}



powerOfTwo :: Integer -> Integer
powerOfTwo 0 = 1
powerOfTwo n = iter (n-1) double 2



-- question 6.


data RhType = Pos | Neg


data ABOType = A | B | AB | O

data BloodType = BloodType ABOType RhType



patient1BT :: BloodType
patient1BT = BloodType A Pos

patient2BT :: BloodType
patient2BT = BloodType O Neg

patient3BT :: BloodType
patient3BT = BloodType AB Pos


showRh :: RhType -> String
showRh Pos = "+"
showRh Neg = "-"
showABO :: ABOType -> String
showABO A = "A"
showABO B = "B"
showABO AB = "AB"
showABO O = "O"
showBloodType :: BloodType -> String
showBloodType (BloodType abo rh)  = showABO abo ++ showRh rh


canDonateTo :: BloodType -> BloodType -> Bool
canDonateTo (BloodType O _) _ = True                      
canDonateTo _ (BloodType AB _) = True                     
canDonateTo (BloodType A _) (BloodType A _) = True
canDonateTo (BloodType B _) (BloodType B _) = True
canDonateTo _ _ = False --otherwise
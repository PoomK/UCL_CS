-- module Coursework where

{-
  Your task is to design a datatype that represents the mathematical concept of a (finite) set of elements (of the same type).
  We have provided you with an interface (do not change this!) but you will need to design the datatype and also 
  support the required functions over sets.
  Any functions you write should maintain the following invariant: no duplication of set elements.

  There are lots of different ways to implement a set. The easiest is to use a list
  (as in the example below). Alternatively, one could use an algebraic data type, or 
  wrap a binary search tree.
  Extra marks will be awarded for efficient implementations if appropriate.

  You are NOT allowed to import anything from the standard library or other libraries.
  Your edit of this file should be completely self-contained.

  DO NOT change the type signatures of the functions below: if you do,
  we will not be able to test them and you will get 0% for that part. While sets are unordered collections,
  we have included the Ord constraint on most signatures: this is to make testing easier.

  You may write as many auxiliary functions as you need. Please include everything in this file.
-}

{-
   PART 1.
   You need to define a Set datatype. Below is an example which uses lists internally.
   It is here as a guide, but also to stop ghci complaining when you load the file.
   Free free to change it.
-}

-- you may change this to your own data type
newtype Set a = Set { unSet :: [a] } deriving (Show)

{-
   PART 2.
   If you do nothing else, at least get the following two functions working. They
   are required for testing purposes.
-}

-- toList {2,1,4,3} => [1,2,3,4]
-- the output must be sorted.
-- toList :: Set a -> [a] (Old signature, not sure how to implement without adding Ord a)
-- toList (Set [2,1,5,6,7,9])
-- Result: [1,2,5,6,7,9]
toList :: (Ord a) => Set a -> [a]
toList (Set b) = quicksort b
quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = quicksort [y | y <- xs, y < x] ++ [x] ++ quicksort [y | y <- xs, y >= x]

-- fromList [2,1,1,4,5] => {2,1,4,5}
-- fromList [2,1,1,4,5,5,7,8,8]
-- Result: Set {unSet = [2,1,4,5,7,8]}
fromList :: Ord a => [a] -> Set a
fromList xs = Set (removeDup xs) 
   where
      removeDup [] = []
      removeDup (x:xs) = x : removeDup (filter (/= x) xs)

{-
   PART 3.
   Your Set should contain the following functions.
   DO NOT CHANGE THE TYPE SIGNATURES.
-}

-- test if two sets have the same elements.
instance (Ord a) => Eq (Set a) where
  s1 == s2 = (toList s1) == (toList s2)

-- the empty set
empty :: Set a
empty = Set []

-- Set with one element
singleton :: a -> Set a
singleton x = Set [x]

-- insert an element of type a into a Set
-- make sure there are no duplicates!
-- insert 1 (Set [2,3,4])
-- Result: Set {unSet = [1,2,3,4]}
insert :: (Ord a) => a -> Set a -> Set a
insert x (Set xs) = fromList (x:xs)
-- !!!!!!!! When inserting, set is not in order

-- join two Sets together
-- be careful not to introduce duplicates.
-- let set1 = Set [1,2,3]
-- let set2 = Set [3,4,5]
-- union set1 set2
-- Result: Set {unSet = [1,2,3,4,5]}
union :: (Ord a) => Set a -> Set a -> Set a
union (Set xs) (Set ys) = fromList (xs ++ ys)

-- return the common elements between two Sets
intersection :: (Ord a) => Set a -> Set a -> Set a
intersection (Set xs) (Set ys) = fromList [x | x <- xs, x `elem` ys]

-- all the elements in Set A *not* in Set B,
-- {1,2,3,4} `difference` {3,4} => {1,2}
-- {} `difference` {0} => {}
difference :: (Ord a) => Set a -> Set a -> Set a
difference = undefined

-- is element *a* in the Set?
member :: (Ord a) => a -> Set a -> Bool
member = undefined


-- how many elements are there in the Set?
cardinality :: Set a -> Int
cardinality = undefined


setmap :: (Ord b) => (a -> b) -> Set a -> Set b
setmap = undefined


setfoldr :: (a -> b -> b) -> Set a -> b -> b
setfoldr = undefined


-- powerset of a set
-- powerset {1,2} => { {}, {1}, {2}, {1,2} }
powerSet :: Set a -> Set (Set a)
powerSet = undefined


-- cartesian product of two sets
cartesian :: Set a -> Set b -> Set (a, b)
cartesian = undefined


-- partition the set into two sets, with
-- all elements that satisfy the predicate on the left,
-- and the rest on the right
partition :: (a -> Bool) -> Set a -> (Set a, Set a)
partition = undefined



{-
   On Marking:
   Be careful! This coursework will be marked using QuickCheck, against Haskell's own
   Data.Set implementation. Each function will be tested for multiple properties.
   Even one failing test means 0 marks for that function.

   Marks will be lost for too much similarity to the Data.Set implementation.

   Pass: creating the Set type and implementing toList and fromList is enough for a
   passing mark of 40%.

-}

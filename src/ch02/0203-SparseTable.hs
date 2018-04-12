st :: [Int] -> Int -> Int -> Int
st a i 0 = a !! i
st a i j = min (st a i j-1) ( st a (i+2^(j-1)) (j-1) )
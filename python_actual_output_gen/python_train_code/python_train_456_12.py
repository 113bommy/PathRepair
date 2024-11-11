n = int (input ())
arr = list (map (int, input ().split()))
print (n - (sum (arr[1:]) % n == 0))

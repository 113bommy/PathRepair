
n, m = map (int, input ().split ())
if abs (m - n) > abs (m - 1) :
    print (m + 1)
elif abs (m - n) < abs (m - 1) :
    print (m - 1)
elif n == 1 :
    print (m)
else :
    print (m + 1)

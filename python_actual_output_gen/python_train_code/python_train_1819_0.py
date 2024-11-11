n,m,min_a,max_a = map(int,input().split())
a = list(map(int,input().split()))
if m <= n-2:
    if min(a) >= min_a and max(a) <= max_a: print("Correct")
    else: print("Incorrect")
elif m == n-1:
    if min(a) == min_a and max(a) <= max_a or min(a) == min_a and max(a) <= max_a: print("Correct")
    else: print("Incorrect")
elif n == m:
    if min(a) == min_a and max(a) == max_a: print("Correct")
    else: print("Incorrect")
else: print("Incorrect")
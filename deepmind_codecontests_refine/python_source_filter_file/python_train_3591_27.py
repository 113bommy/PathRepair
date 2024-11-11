n,m = [int(x) for x in input().split()]
 
if n%2 == 0:
    if m > n//2:
        print(m-1)
    else:
        print(m+1)
else:
    if m > (n+1)//2:
        print(m-1)
    elif m < (n + 1)//2:
        print(m+1)
    elif n > 1:
        print(m)
    else:
        print(m-1)

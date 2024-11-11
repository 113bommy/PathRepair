import math
tc=int(input())
for ctr in range(tc):
    n=int(input())
    if n<=30:
        print("NO")
    else:
        print("YES")
        if n==36 or n==40 or n==44:
            print(6,10,15,n-31)
        else:
            print(6,10,14,n-30)

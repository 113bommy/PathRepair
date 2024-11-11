import math
n = int(input())
while n:
    l,r,d = list(map(int, input().split(" ")))

    k1 = math.floor(r/d) + 1
    k2 = math.ceil(l/d) - 1
    if( d == 1 and l == 1):
        print(1 + r)
    else:

        if(d < r):
            print(d)
        else:
            if(k2 != 0):
                print(k2*d)
        
            else:
                print(k1*d)
    n = n - 1

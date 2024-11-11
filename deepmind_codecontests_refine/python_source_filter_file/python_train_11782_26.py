import math
import operator


T = int(input())
while(T != 0):
    T -= 1

    n,k,a,b = map(int, input().split())
    if(b * k >= n):
        print(-1)
    else:
        if(n - a * ((n - b * k) // (a - b)) - (k - (n - b * k) // (a - b)) * b == 0 and (n - b * k) // (a - b) == k):
            print(min(k,(n - b * k) // (a - b) - 1))
        else:
            print(min(k, (n - b * k) // (a - b) ))

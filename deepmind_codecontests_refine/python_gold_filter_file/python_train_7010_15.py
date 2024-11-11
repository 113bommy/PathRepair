import math
n,m = map(int,input().split())
c = 0
if n ==0 and m>n:
    print('Impossible')
elif m == 0 :
    print(n,n)
elif n == 1:
    c = c+n+(m-1)
    print(c,c)
elif m <= n:
    print(n,(n+m)-1)
elif m>n:
    print(m,(m+n-1))

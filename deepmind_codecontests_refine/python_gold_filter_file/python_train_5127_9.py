import math
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    if n%2==0:
        print(n+2*k)
    else:
        res=n
        for i in range(3, int(math.sqrt(n))+1,2):
            if n%i==0:
                res=i
                break
        print(n+res+2*(k-1))

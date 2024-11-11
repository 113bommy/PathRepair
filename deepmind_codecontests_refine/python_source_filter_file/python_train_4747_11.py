from math import sqrt
n,k = map(int,input().split())
d = 10000000000000
if n < k*(k+1)//2:
    print(-1)
else:
    for i in range(1,int(sqrt(n))+1):
        if n%i==0:
            if i == k*(k+1)//2:
                d = i
                break
            if n//i >= (k*(k+1))//2:
                d = min(d,n//i)
    for i in range(1,k):
        print(i*n//d,end=" ")
    print((n//d * (k+d-(k*(k+1)//2))),end=" ")
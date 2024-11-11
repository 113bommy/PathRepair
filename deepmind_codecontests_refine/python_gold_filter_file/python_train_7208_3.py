from math import ceil
t=int(input())
while t:
    n,m,k=map(int,input().split())
    a=n//k
    if(a>=m):
        print(m)
    else:
        m=m-a
        e=ceil(m/(k-1))
        print(a-e)
    t-=1
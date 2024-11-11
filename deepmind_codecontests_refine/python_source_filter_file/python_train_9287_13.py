import math as m
t=int(input())
while(t):
    n,d = map(int,input().split(' '))
    ans=100000000000
    i=0
    while(i*i<=n):
        if i+m.ceil(d/(i+1))<ans:
            ans=i+m.ceil(d/(i+1))
        i+=1
    print("YES" if ans<=n else "NO")
    t-=1
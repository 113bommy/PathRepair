### B. Different Rules
for _ in range(int(input())):
    n,x,y=map(int,input().split())
    minim=min(x+y-1, n)
    m=min(x+y-n+1, n)
    maxim=max(m,1)
    print(minim, maxim)
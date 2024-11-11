t=int(input())
while(t):
    t-=1
    n=int(input())
    c=0
    v=n//2
    p=n//2
    for i in range(n,v,-2):
        c+=(4*i-4)*p
        p-=1
    print(c)
        
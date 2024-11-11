for i in range(int(input())):
    a=int(input())
    t=list(map(int,input().split()))
    p=sum(t)
    for j in range(p,10000):
        s=j//a
        if s*a>=p:
            print(s)
            break

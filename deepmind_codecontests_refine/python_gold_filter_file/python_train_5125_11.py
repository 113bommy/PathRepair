t=int(input())
for i in range(t):
    n,d=map(int,input().split())
    l=[int(i) for i in input().split()]
    for j in range(1,len(l)):
        x=min(l[j],d//j)
        d-=x*j
        if d<0:
            break
        else:
            l[0]+=x
    print(l[0])

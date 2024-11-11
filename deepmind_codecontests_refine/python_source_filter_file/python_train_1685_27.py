t=int(input())
while(t):
    n=int(input())
    lista=[int(x) for x in input().split()]
    ans=0
    mn=1000000000
    for x in range(n):
        if lista[x]>mn:
            ans+=1
        mn=min(mn,lista[x])
    print(ans)
    t=t-1
    

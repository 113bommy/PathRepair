for _ in range(int(input())):
    n,m=[int(i) for i in input().split()]
    l=[]
    for i in range(n):
        l.append(list(map(int, input().split())))
    ans=0
    least=int(1e9)
    exist=0
    for i in range(n):
        for j in range(m):
            ans+=(abs(l[i][j]))
            least=min(least, abs(l[i][j]))
            if(l[i][j]<0): exist+=1
    if(exist%2==1): print(ans-2*least)
    else: print(ans)      
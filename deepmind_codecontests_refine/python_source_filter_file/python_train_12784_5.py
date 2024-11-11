N,X=map(int,input().split())
L=list(map(int,input().split()))
mem=1; ans=0
for i in L:
    mem+=i
    if mem<=X: ans+=1
print(ans)
from itertools import combinations_with_replacement
n,m,q=map(int,input().split())
l=[list(map(int,input().split())) for i in range(q)]
ans=0
for i in combinations_with_replacement([i for i in range(1,11)], n):
    tmp=0
    for a,b,c,d in l:
        if i[b-1]-i[a-1]==c:
            tmp+=d
    ans=max(ans,tmp)
print(ans)
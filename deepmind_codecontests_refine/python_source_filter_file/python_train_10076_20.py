n=int(input())
a=map(int,input().split())
ans=0
c=10**5+1
for i in a:
    c=min(i,c)
    if c==i:
        ans+=1
print(ans)
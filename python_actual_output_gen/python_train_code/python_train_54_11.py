n,c=map(int,input().split())
l=list(map(int,input().split()))
ans=0
for i in range(1,n):
    if (l[i-1]-l[i])>ans:
        ans=l[i-1]-l[i]
if ans>c:
    print(ans-c)
else:
    print(ans)
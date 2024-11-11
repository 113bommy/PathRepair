n,m=[int(i) for i in input().split()]
ans=0
while(n<m):
    if m%2:m+=1
    else:m//=2
    ans+=1
if n>m:
    ans+=(n-m)
print(ans)
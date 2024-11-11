n,m = map(int,input().split())
ans = 1
for i in range(1,int(m**0.5)+1):
    if m%i!=0:continue
    if m//i>=n:
        ans = max(i,ans)
    if i>=m:
        ans = max(m//i,ans)

print(ans)
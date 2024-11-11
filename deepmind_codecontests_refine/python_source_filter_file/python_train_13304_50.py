l,r = map(int,input().split())
ans = 2019
for i in range(l,min(l+2019,r)+1):
    for j in range(l+1,min(l+2019,r)+1):
        ans = min(ans,i*j%2019)
print(ans)
l,r = map(int,input().split())
r = min(r,l+673)
ans = 2018

for i in range(l,r+1):
    for j in range(i+1,r+1):
        ans = min(i*j%673,ans)
print(ans)
l,r=map(int,input().split())
if l-r>=2019:
    print(0)
    exit()
ans=2020
for i in range(l,r+1):
    for j in range(i+1,r+1):
        ans=min((i*j)%2019,ans)
print(ans)
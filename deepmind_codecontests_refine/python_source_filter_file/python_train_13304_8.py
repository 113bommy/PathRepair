l,r=map(int,input().split())
if l//2019!=r//2019:
    print(0)
    exit()

ans=2019
for i in range(l,r):
    for k in range(i+1,r+1):
        ans=min(ans,(i%2019)*(k%2019))
print(ans)
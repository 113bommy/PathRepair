n,x=map(int,input().split())
L=list(map(int,input().split()))
ans=0
d=0
for i in range(1,n):
    d += L[0]
    if d>x:break
    ans += 1
print(ans)
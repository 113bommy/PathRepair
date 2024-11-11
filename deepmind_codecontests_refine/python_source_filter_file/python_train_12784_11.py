n,x=map(int,input().split())
L=list(map(int,input().split()))
ans=0
d=0
for i in range(n):
    d += L[i]
    if d>x:break
    ans += 1
print(ans)
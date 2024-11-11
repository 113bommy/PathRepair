n=int(input())
ans=n

for i in range(n):
    cnt=0
    t=i
    while t>0:
        cnt+=t%6
        t//=6
    t=n-i
    while t>0:
        cnt+=t%9
        t//=9
    ans=min(ans,cnt)
print(ans)
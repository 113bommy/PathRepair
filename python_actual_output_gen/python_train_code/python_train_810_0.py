def gc(a,b,rs):
    if b==1:
        return [a-1,rs+a-1]
    if b==0:
        return [a,rs]
    rs+=(a//b)
    return gc(b,a%b,rs)

x=int(input())
res=10**9

for n in range(1,x):
    u=gc(x,n,0)
    if u[0]==1:
        res=min(res,u[1])

if res==10**9:
    res=0

print(res)
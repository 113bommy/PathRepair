import math
n=int(input())
ls=[]
for _ in range(n):
    ls.append(tuple(map(int,input().split())))

ans=0
for x,y in ls:
    ans=math.gcd(x*y,ans)
for x,y in ls:
    if math.gcd(ans,x)>1:
        ans=math.gcd(ans,x)
    else:
        ans=math.gcd(ans, y)


print(-1 if ans==-1 else ans)




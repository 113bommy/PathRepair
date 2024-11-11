n=int(input())
xy=[tuple(map(int, input().split())) for _ in range(n)]

fn=[lambda x:x[0]+x[1],lambda x:x[0]+x[1]]
ans=0
for f in fn:
    xy.sort(key = f)
    ans=max(ans,abs(f(xy[0])-f(xy[-1])))
print(ans)
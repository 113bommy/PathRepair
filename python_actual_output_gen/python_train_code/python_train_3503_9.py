N,K = map(int,input().split())
lis = []
val = 0
ans = 0
s = set()
dub = []

for _ in range(N):
    lis.append(tuple(map(int,input().split())))

lis = sorted(lis,key=lambda x: x[1],reverse=True)

for t,v in lis[:K]:

    if t in s:
        dub.append(v)
    s.add(t)
    val += v

ans = val + len(s) ** 2

for t,v in lis[K:]:
    if len(dub) == 0:
        break
    if t in s:
        continue

    s.add(t)
    r = dub.pop()
    val += v - r
    ans = max(ans,val+len(s) ** 2)

    print(ans)
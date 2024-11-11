n,k = map(int, input().split())
a = list(map(int, input().split()))
t = sum(a)
r = set()
r.add(t)
for i in range(2,int(t**0.5)+2):
    if t%i == 0:
        r.add(i)
        r.add(t//i)
ans = 1
for i in r:
    f = [x%i for x in a]
    f.sort()
    if sum(f[:-sum(f)//i]) <= k:
        ans = max(ans,i)
print(ans)

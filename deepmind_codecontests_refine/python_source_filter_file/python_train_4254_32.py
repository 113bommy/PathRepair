N,M=map(int,input().split())
import collections
e =[]
for i in range(N):
    ta,tb =map(int,input().split())
    e.extend([ta,tb])
c = collections.Counter(e)
print(c)
ans = "YES"
for i in c:
    if c[i]%2 != 0:
        ans = "NO"
print(ans)

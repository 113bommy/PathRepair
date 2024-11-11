s = list(str(input()))
t = list(str(input()))

X = [[] for _ in range(26)]
for i, c in enumerate(s):
    j = ord(c)-ord('a')
    X[j].append(i)

ans = 0
import bisect
cur = -1
for c in t:
    j = ord(c)-ord('a')
    if len(X[j]) == 0:
        print(-1)
        exit()
    k = bisect.bisect_left(X[j], cur)
    if k != len(X[j]):
        cur = X[j][k]
    else:
        cur = X[j][0]
        ans += len(s)
ans += cur+1
print(ans)

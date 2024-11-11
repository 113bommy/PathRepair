n, k = map(int, input().split())
a = list(map(int, input().split()))
s = list(map(int, input().split()))
d = [0]*(n+5)
for q in range(n):
    d[s[q]] = q
f, q2 = [], 0
for q in range(len(a)):
    if q-1 == q2:
        f.append(q)
    q2 = max(q2, d[a[q]])
f.append(n)
if len(f) < k:
    print('NO')
else:
    print('YES')
    g = [chr(ord('a')+q) for q in range(30)]
    ans = ['' for q in range(n)]
    q1 = 0
    for q in range(n):
        if f[q1] == q:
            q1 += 1
            q1 = min(q1, 26)
        ans[a[q]-1] = g[q1]
    print(''.join(ans))

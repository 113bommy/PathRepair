import sys
n, k = map(int, input().split())
s = list(input())
mn = list(set(s))
mn.sort()
if k > n:
    s += mn[0] * (k - n)
    print(''.join(s))
    sys.exit(0)
suf_min = s.copy() + [mn[-1]]
for i in range(n - 1, -1, -1):
    suf_min[i] = min(suf_min[i], suf_min[i + 1])
ans = ''
f = False
for i in range(k):
    if f:
        ans += mn[0]
    elif suf_min[i + 1] != mn[-1] and i != k - 1:
        ans += s[i]
    else:
        ans += mn[min(mn.index(s[i]) + 1, len(mn) - 1)]
        f = True
print(ans)
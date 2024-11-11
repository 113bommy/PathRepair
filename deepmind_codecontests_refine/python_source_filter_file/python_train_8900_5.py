n = int(input())
hs = list(map(int, input().split()))
chs = list(set(hs))
chs.sort()
rchs = {}
for i, v in enumerate(chs):
    rchs[v] = i
for i in range(n):
    hs[i] = rchs[hs[i]]
max_h = -1
rs = []
max_hs = [0] * n
for i, h in enumerate(hs):
    max_h = max(max_h, h)
    rs.append((h, i))
    max_hs[i] = max_h
    
h, r = 0, -1
p = 0
ans = 0
while r < n - 1:
    nh, nr = rs[p]
    if r >= nr:
        p += 1
    else:
        r = nr
        p += 1
        while r < n - 1:
            nh, nr = rs[p]
            if nh >= max_hs[r]:
                break
            r = max(r, nr)
            p += 1
        ans += 1
print(ans)

n = int(input().strip())
p = [0 for i in range(n)]
p[0] = -1
index = 1
for i in input().strip().split():
    p[index] = int(i) - 1
    index += 1

min_ = [100000000000 for i in range(n)]
s = []
for i in input().strip().split():
    val = int(i)
    s.append(val)

for i in range(1,n):
    if s[i] >= 0 and s[p[i]] < 0:
        min_[p[i]] = min(min_[p[i]],s[i])

for i in range(1,n):
    if s[i] < 0:
        got = min_[i]
        if got == 100000000000:
            got = s[p[i]]
        s[i] = got
res = s[0]
impossible = False
for i in range(1,n):
    if s[i] < s[p[i]]:
        impossible = True
        break
    res += s[i] - s[p[i]]
if impossible:
    print(-1)
else:
    print(res)

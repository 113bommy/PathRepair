s = input().split()
k = int(s[1])
v = []
for x in s[0]:
    v.append(int(x))
ans = 0
for i in range(len(v) - 1):
    m, index = 0, -1
    for j in range(i, len(v)):
        if v[j] > m and j - i <= k:
            m = v[j]
            index = j
    for j in range(index, i, -1):
        v[j], v[j - 1] = v[j - 1], v[j]
    k -= (index - i)
    if k == 0:
        break
ans = 0
for x in v:
    ans = ans * 10 + x
print(ans)
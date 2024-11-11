n = int(input())
s = list(input())
t = list(input())

c = []
for i in range(n):
    m = i
    while (m < n) and (s[m] != t[i]):
        m += 1
    if m >= n:
        c = None
        break
    for j in range(m - 1, i - 1, -1):
        c.append(j + 1)
        s[j], s[j + 1] = s[j + 1], s[j]
if c == None:
    print(c)
else:
    print(len(c))
    print(*c)

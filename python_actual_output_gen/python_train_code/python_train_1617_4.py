s = input()
m = ['z' for i in range(len(s))]
m[-1] = s[-1]
c = s[-1]
for i in range(len(s) - 2, -1, -1):
    if s[i] < c:
        c = s[i]
    m[i] = c
ind = m.index(min(m))
l = []
res = ''
for i in range(len(s)):
    while l and l[-1] < m[i]:
        res += l.pop()
    l.append(s[i])
print(res + ''.join(map(str, (l[::-1]))))

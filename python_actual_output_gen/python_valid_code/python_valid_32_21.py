n, k = map(int, input().split())
s = input()
d = dict()
for x in s:
    d.setdefault(x, 0)
    d[x] = d[x] + 1 
k = d[s[0]]
b = True
for x in d:
    if d[x] != k:
        b = False
        break
if b:
    print('YES')
else:
    print('NO')

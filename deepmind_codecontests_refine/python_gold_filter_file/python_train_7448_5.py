from sys import *

n, m, c = input().split()
n = int(n)
m = int(m)
l = ['.' * (m + 2)] + ['.' + input() + '.' for i in range(n)] + ['.' * (m + 2)]
#print(*l)
ans = []
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if l[i][j] == c:
            if l[i + 1][j] != '.': ans.append(l[i + 1][j])
            if l[i - 1][j] != '.': ans.append(l[i - 1][j])
            if l[i][j + 1] != '.': ans.append(l[i][j + 1])
            if l[i][j - 1] != '.': ans.append(l[i][j - 1])

s = set(ans)
#print(*s)
s.discard(c)
print(len(s))
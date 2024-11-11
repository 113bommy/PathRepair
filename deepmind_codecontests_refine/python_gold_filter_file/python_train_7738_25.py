n,k = map(int,input().split())
import math
s = [2]
ss = []
for i in range(3,n+1):
    m = int(math.sqrt(i))
    c = 0
    for j in range(m):
        c = c + 1
        if i%(j+2) == 0:
            break
        if c > m - 1:
            s.append(i)

for i in range(len(s)-1):
    p = s[i] + s[i+1] + 1
    ss.append(p)
s = set(s)
ss = set(ss)
sss = s & ss

if len(sss) >= k:
    print('YES')
else:
    print('NO')
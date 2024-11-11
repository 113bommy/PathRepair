from collections import Counter
N, M = map(int, input().split())
c = []
for i in range(N):
    a, b = map(int, input().split())
    c.append(a)
    c.append(b)
c = Counter(c)
if all(cnt%2==0 for cnt in c.values()):
    print('YES')
else:
    print('NO')
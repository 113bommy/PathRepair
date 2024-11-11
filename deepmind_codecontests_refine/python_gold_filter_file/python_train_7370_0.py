from collections import defaultdict as ddict
d = ddict(int)
d[0] = 0
n = int(input())
l = [tuple(map(int, input().split())) for _ in range(n)]
l.sort()
for i in range(n-1):
  for j in range(i+1,n):
    curx = l[j][0] - l[i][0]
    cury = l[j][1] - l[i][1]
    d[(curx,cury)] += 1
print(n-max(d.values()))
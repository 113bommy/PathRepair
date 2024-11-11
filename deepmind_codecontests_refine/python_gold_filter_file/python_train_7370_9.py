from collections import Counter
n = int(input())
xy = [tuple([int(_) for _ in input().split()]) for i in range(n)]
if n == 1:
    result = 1
else:
    xy.sort()
    dxy = [(xy[i][0]-xy[j][0], xy[i][1]-xy[j][1])
           for i in range(n)
           for j in range(i+1, n)]
    cdxy = Counter(dxy)
    result = n - max(cdxy.values())
print(result)
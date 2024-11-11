import sys,heapq
printn = lambda x: sys.stdout.write(x)
DBG =  True
def ddprint(x):
  if DBG:
    print(x)

n,k =      map(int, input().split())
t = []
b = []
a = []
for i in range(n):
    ti,bi =      map(int, input().split())
    t.append(ti)
    b.append(bi)
    a.append((ti,bi))

a.sort(key=lambda x: -x[1])
ddprint(a)

mx = -1
lensum = 0
c = []
for i in range(n):
    ti,bi = a[i]
    if len(c) < k:
        heapq.heappush(c, ti)
        lensum += ti
    else:
        l = heapq.heappushpop(c, ti)
        lensum += ti - l
    mx = max(mx, lensum*bi)

print(mx)

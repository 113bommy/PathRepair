import sys,heapq,bisect
from collections import deque,defaultdict
printn = lambda x: sys.stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True  and False
def ddprint(x):
  if DBG:
    print(x)

n = inn()
a = inl()
a.sort()
ddprint(a)
sum = 0
for i in range(n-1):
    ai = a[i]
    if ai < 0:
        p1 = bisect.bisect_right(a,ai//2)
        p2 = bisect.bisect_left(a,(-ai+1)//2)
        p3 = bisect.bisect_right(a,(-ai)*2)
        ddprint("i {} ai {} p123 {} {} {}".format(i,ai,p1,p2,p3))
        sum += (p1-i-1) + (p3-p2)
    elif ai > 0:
        p4 = bisect.bisect_left(a,(ai+1)//2)
        p5 = bisect.bisect_right(a,(ai)*2)
        ddprint("i {} ai {} p45 {} {}".format(i,ai,p4,p5))
        sum += (p5-p4-1)

print(sum)

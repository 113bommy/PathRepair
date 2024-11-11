from heapq import *
t = int(input())
for _ in range(t):
    n = int(input())
    a = [0] * n
    hq = [(-n, 0, n - 1)]
    #print("Heap",hq)
    for i in range(1, n + 1):
        _, l, r = heappop(hq)
        #print("_",_,"l",l,"r",r)
        m = (l + r) // 2
        a[m] = i
        if m > l:
            heappush(hq, (l - m, l, m - 1))
        if m < r:
            heappush(hq, (m - r, m + 1, r))
 
    print(*a)
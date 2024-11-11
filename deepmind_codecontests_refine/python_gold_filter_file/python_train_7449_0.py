import heapq as hq
from math import ceil
n, k, x = [int(i) for i in input().strip().split(' ')]
arr = [int(i) for i in input().strip().split(' ')]
is_neg = False
for i in arr:
    if i < 0:
        is_neg = True if is_neg == False else False

narr = [[abs(i), pos, i < 0] for pos, i in enumerate(arr)]
hq.heapify(narr)
if is_neg:
    while k > 0:
        hq.heapreplace(narr, [narr[0][0]+x, narr[0][1], narr[0][2]])
        k -= 1
else:
    minode = hq.heappop(narr)
    mi = minode[0]
    kswitch = ceil(mi/x) #make the off number of negatives
    if kswitch > k:
        kswitch = k
    else:
        minode[2] = False if minode[2] == True else True
    k -= kswitch

    hq.heappush(narr, [abs(mi-kswitch*x), minode[1], minode[2]])
    while k > 0:
        hq.heapreplace(narr, [narr[0][0]+x, narr[0][1], narr[0][2]])
        k -= 1

narr = sorted(narr, key=lambda x:x[1])
arr = [str(i[0]*(-1 if i[2] else 1)) for i in narr]
print(" ".join(arr))
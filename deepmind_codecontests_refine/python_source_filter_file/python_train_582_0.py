from heapq import *

N = int(input())
price = [int(i) for i in input().split()]

total = 0
inf = 3 * (10**5) + 1
h = [inf]

#Assume we bought and sold optimally for the first k prices.
#We adjust our answer for the (k+1)th price that comes up.
for p in price:
    if p > h[0]:
        total += (p - heappop(h))
        #We push p onto heap in case we should have bought at this price instead
        #of selling.
        heappush(h, p)
    heappush(h, p)

print(total)
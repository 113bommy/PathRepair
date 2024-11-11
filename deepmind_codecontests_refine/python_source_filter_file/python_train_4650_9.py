from math import fabs
import heapq

def getError(l, size):
	r = 0
	for i in range(size):
 		r += l[i]**2
	return r
  

pq = []
n, k1, k2 = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
disp = k1 + k2

for i in range(n):
	pq.extend([int((-1)*fabs(a[i] - b[i]))])
heapq.heapify(pq)

while disp > 0:
	x = heapq.heappop(pq)
	if x == 0: heapq.heappush(pq, 1)
	else: heapq.heappush(pq, x - 1)
	disp -= 1

print(getError(pq, len(pq)))
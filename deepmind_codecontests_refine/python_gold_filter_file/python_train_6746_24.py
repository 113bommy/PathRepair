import bisect
from collections import deque
N = int(input())
A = [int(input()) for i in [0]*N]


ls = deque([A[0]])
for a in A[1:]:
	ind = bisect.bisect_left(ls,a)
	if ind == 0:
		ls.appendleft(a)
	else:
		ls[ind-1] = a

print(len(ls))





# your code goes here
# your code goes here
import bisect
n, m, ta, tb, k = input().split()

n = int(n)
m = int(m)
ta = int(ta)
tb = int(tb)
k = int(k)

if k >= m or k >= n:
	print(-1)
	exit()

a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort()
b.sort()

e = 0
flag = True
for i in range(k):
	arriveAtB = a[i] + ta
	r = k - i
	d = bisect.bisect_right(b, arriveAtB)
	if b[d-1] == arriveAtB:
		d -= 1
	if d + r >= len(b):
		flag = False
	else:
		e = max(b[d+r] + tb, e)
		
if flag:
	print(e)
else:
	print(-1)
	
	
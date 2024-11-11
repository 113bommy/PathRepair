import math
from bisect import bisect_right
arr = [2]
t = 4
v = 1
while arr[-1]<=10**9:
	arr.append(arr[-1] + t+v)
	t += 2
	v+=1
for _ in range(int(input())):
	n = int(input())
	ans = 0
	while n>=2:
		v = bisect_right(arr,n,0,len(arr))
		n-= arr[v-1]
		ans += 1
	print(ans)

from collections import defaultdict, Counter

n, x = [int(i) for i in input().split()]
temp = []
arr = [-1]*n
for i in range(x):
	sw, l, r = [int(i) for i in input().split()]
	temp.append([sw, l, r])
	if sw == 1:
		for i in range(l-1, r-1):
			arr[i] = 0
	
if all([min(arr[l-1: r]) == -1 for sw, l, r in temp if sw == 0]):
	ans = [n]
	for i in range(n-1):
		ans.append(ans[-1]+arr[i])
	print("YES")
	print(*ans)
else:
	print("NO")
	
	
	
	
			

from collections import *
import sys  
input=sys.stdin.readline

# "". join(strings)  
    
def ri():
    return int(input())
 
def rl():
    return list(map(int, input().split()))
    

t =ri()
for _ in range(t):
	n =ri()
	aa =rl()
	dd = defaultdict(list)
	for i, ai in enumerate(aa):
		dd[ai].append(i + 1)
	for key in dd.keys():
		dd[key].append(0)
		dd[key].append(n + 1)
	gaps = defaultdict(int)
	for key in dd.keys():
		dd[key].sort()
		gaps[key] = max([dd[key][i] - dd[key][i - 1] - 1 for i in range(1,len(dd[key]))])
	print(gaps)
	ans = [10**18] * n
	for key in gaps.keys():
		ans[gaps[key]] = min(ans[gaps[key]], key)
	for i in range(1, n):
		ans[i] = min(ans[i], ans[i - 1])

	for i in range(n):
		if ans[i] == 10**18:
			ans[i] = -1	
	print(" ".join([str(x) for x in ans]))

	


	



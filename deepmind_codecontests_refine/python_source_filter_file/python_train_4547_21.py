import math
getInputList = lambda : list(input().split())
getInputIntList = lambda : list(map(int,input().split()))


n = int(input())

arr = getInputIntList()
arr.sort()
ans = 0
s = sum(arr)
for i in arr:
	if round(round(s/n,1) + 0.01)  == 5:
		print(ans)
		break
	s += 5 - i
	ans += 1
else:
	print(ans)
	

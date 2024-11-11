# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
# import math 
# import collections
# ===================================
n = int(input())
q = [int(x) for x in input().split()]
for i in range(n-1):
	if abs(q[i]-q[i+1]) != 1:
		print("NO")
		break
else:
	print("YES")
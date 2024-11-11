# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
# import math 
# import collections
# import string
# ===================================
n = int(input())
ans = []
for i in range(n):
	temp = []
	for j in range(2*(n-1) - 2*i):
		temp.append("")
	for j in range(i):
		temp.append(j)
	for j in range(i, -1, -1):
		temp.append(j)
	s = " ".join(map(str, temp))
	ans.append(s)
for i in range(n):
	print(ans[i])
for i in range(n-2, -1, -1):
	print(ans[i])
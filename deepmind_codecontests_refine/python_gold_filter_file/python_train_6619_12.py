# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
# import math, fractions, collections
# ===================================
n = int(input())
q = [int(x) for x in input().split()]
ans = -n
s = set()
for i in range(2*n):
	temp = q[i]
	if temp in s:
		s.remove(temp)
	else:
		s.add(temp)
	ans = max(ans, len(s))
print(ans)

# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
# import math 
# import collections
# ===================================
s = str(input())
ans = ""
flag = 0
for i in range(len(s)):
	x = s[i]
	if not flag:
		if x == "1":
			flag = 1
		ans += x
	else:
		if x == "0" or i == len(s)-1:
			ans += s[i+1:]
			break
		ans += x
print(ans)
			

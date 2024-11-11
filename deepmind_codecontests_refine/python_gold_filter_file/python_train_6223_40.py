s = input()
t = input()
ans = len(t)
for i in range(len(s)-len(t)+1):
	diff = 0
	for j in range(len(t)):
		if not s[i+j] == t[j]:
			diff=diff+1
	ans = min(ans, diff)
print(ans)
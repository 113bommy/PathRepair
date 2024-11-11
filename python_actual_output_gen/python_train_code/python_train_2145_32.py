s = input()
t = input()

ans = []
for i in range(len(s)-len(t)):
	count = 0
	for j in range(len(t)):
		if s[i+j] != t[j]:
			count += 1
	ans.append(count) 

print(min(ans))

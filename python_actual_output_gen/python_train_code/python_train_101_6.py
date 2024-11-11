s=input()
for i in range(len(s)):
	for j in range(i):
		if s[:j]+s[i:]=="keyence":
			print("YES")
			exit()
print("NO")
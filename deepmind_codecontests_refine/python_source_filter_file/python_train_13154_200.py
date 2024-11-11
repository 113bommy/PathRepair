s = list(input())
s.sort()
dupl = []
for i in range(len(s) - 1):
	if (s[i] != s[i + 1]):
		dupl.append(s[i])
dupl.append(s[len(s) - 1])

if (len(dupl) % 2 == 0):
	print("CHAR WITH HER!")
else:
	print("IGNORE HIM!")

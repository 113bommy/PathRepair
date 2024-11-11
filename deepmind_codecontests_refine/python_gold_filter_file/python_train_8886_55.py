n = int(input())
s = input()

times = 0
for i in range(len(s)-1, 0, -1):
	if s[i] == s[i-1]:
		times += 1
print(times)

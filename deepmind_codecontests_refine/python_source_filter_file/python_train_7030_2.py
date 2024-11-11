s = list(input())
n = len(s)
for i in range(1, n - 1):
	if s[i] == s[i - 1]:
		for x in range(26):
			if (ord('a') + x != ord(s[i - 1])) and (ord('a') + x != ord(s[i + 1])):
				s[i] = chr(ord('a') + x)
				break
if len(s) > 2 and s[n - 1] == s[n - 2]:
	for x in range(26):
		if ord('a') + x != ord(s[n - 2]):
			s[n - 1] = chr(ord('a') + x)
			break
print(''.join(s))

def check(s):
	for i in range(len(s)):
		if s[i] != s[len(s) - i - 1]:
			return False
	return True
s = input()
for i in range(len(s) + 1):
	for c in range(ord('a'), ord('z') + 1):
		ss = s[:i] + chr(c) + s[i + 1:]
		if check(ss):
			print(ss)
			exit(0)
print("NA")
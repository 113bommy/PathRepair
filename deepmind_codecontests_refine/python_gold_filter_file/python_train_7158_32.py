s = input()
n = len(s)
f = 0
for i  in range(n - 2):
		if s[i] != '.' and s[i+1] != '.' and s[i+2] != '.':
				if s[i+1] != s[i]:
						if s[i+2] != s[i] and s[i+2] != s[i + 1]:
								f = 1
								break

if f == 1:
		print('Yes')
else:
		print('No')

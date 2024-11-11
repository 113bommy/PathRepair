n, t = map(int, input().split())
s = str(input())

s = list(s)

while t:
	i = 0
	while i < n-1:
		if s[i] == 'B' and s[i+1] == 'G':
			s[i] = 'G'
			s[i+1] = 'B'
			i += 2
		i += 1

	t -= 1

print("".join(s))
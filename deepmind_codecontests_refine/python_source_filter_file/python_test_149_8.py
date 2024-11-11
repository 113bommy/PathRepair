t = int(input())

for _ in range(t):
	n, k, x = map(int, input().split())
	s = input()
	s = s[::-1]
	ans = ''
	i = 0
	while i < n:
		if s[i] == 'a':
			ans += 'a'
		else:
			j = i
			while j+1 < n and s[j+1] == s[i]:
				j += 1
			c = (j-i+1) * k + 1
			c1 = x % c
			ans += 'b' * c1
			x = x // c
			i =j
		i += 1
	print(ans[::-1])
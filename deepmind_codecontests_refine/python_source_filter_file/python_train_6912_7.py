n = int(input())
s = input()
i = n
ans = 0
while i < len(s):
	if s[n - 1] == s[n - 2] and s[n - 2] == s[n - 3]:
		ans += 1
	i += n
print(ans)

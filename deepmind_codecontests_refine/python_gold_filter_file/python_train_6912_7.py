n = int(input())
s = input()
i = n
ans = 0
while i < len(s):
	if s[i - 1] == s[i - 2] and s[i - 2] == s[i - 3]:
		ans += 1
	i += n
print(ans)

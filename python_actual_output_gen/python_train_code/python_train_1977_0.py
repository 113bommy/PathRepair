s = input()
m = int(input()) 
pw = [0] * (len(s) + 1)
pw[0] = 1
for i in range(1, len(s) + 1):
	pw[i] = pw[i - 1] * 10 % m
cur = 0
for i in range(len(s)):
	cur *= 10
	cur += ord(s[i]) - ord('0')
	cur %= m
ans = cur
for i in range(1, len(s)):
	cur *= 10
	cur %= m
	cur -= ((ord(s[i - 1]) - ord('0')) * pw[len(s) - i - 1] % m);
	cur += m
	cur %= m
	cur += ord(s[i - 1]) - ord('0')
	cur %= m
	if (s[i] != '0'):
		ans = min(ans, cur)
print(ans)
		

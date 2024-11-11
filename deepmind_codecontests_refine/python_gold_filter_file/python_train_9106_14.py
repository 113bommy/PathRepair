def pal(s):
	n = len(s)
	for i in range(n):
		if s[i] != s[n-i-1]:
			return False
	return True

s = input()
k = int(input())
ans = 'NO'
if len(s) % k == 0:
	n = len(s) // k
	for i in range(k):
		if not pal(s[n * i: n * (i + 1)]):
			break
	else:
		ans = 'YES'
print(ans)
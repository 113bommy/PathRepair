n, p = map(int, input().split())
s = input()
if p == 2:
	ans = 0
	for i in range(n):
		if int(s[i]) % 2 == 0:
			ans += i+1
	print(ans)
elif p == 5:
	ans = 0
	for i in range(n):
		if s[i] == "5" or s[i] == "0":
			ans += i+1
	print(ans)

else:
	mods = [0 for _ in range(p)]
	cur = 0
	mods[0] += 1
	t = s[::-1]
	for i in range(n):
		cur = (cur + int(t[i]) * (10 ** i)) % p
		mods[cur] += 1
	#print(mods)
	ans = 0
	for m in mods:
		ans += (m * (m-1)) // 2
	print(ans)
n = int(input())
s = input()
x = int(s, 2)
p = s.count("1")
if p > 2:
	pre0 = x%(p-1)
pre1 = x%(p+1)

nxt = [i for i in range(n+10)]
for i in range(1, n+10):
	nxt[i] %= bin(i).count("1")

for i in range(n):
	if x == 1<<(n-1-i):
		print(0)
		continue
	if s[i] == "0":
		tmp = (pre1 + pow(2, n-1-i, p+1)) % (p+1)
	else:
		tmp = (pre0 - pow(2, n-1-i, p-1)) % (p-1)
	ans = 1
	while tmp > 0:
		ans += 1
		tmp = nxt[tmp]
	print(ans)
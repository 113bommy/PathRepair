n, a, b, c, d = [int(i) for i in input().split()]
s = input()
res = "YES"
e = max(c,d)
if "##" in s[a-1:e-1]:
	res = "NO"
elif c > d:
	if "..." not in s[b-2:d+1]:
		res = "NO"
print(res)

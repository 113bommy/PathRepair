n, m = map(int, input().split())
s = input().split()
a = dict()
for i in range(m):
	if s[i] in a:
		a[s[i]]+=1
	else:
		a[s[i]] = 1
mn = 1e9
for i in range(1, n+1):
	val = 0
	if str(i) in a:
		val = a[str(i)]
	mn = min(mn, val)
print(val)
n, m = [int(x) for x in input().split()]
ans = ""
less = m-1
last = n-1
for r in range(n):
	if r%2 == 0:
		ans += "#" * m
	else:
		if r // 2 == 0:
			ans += "." * less + "#"
		else:
			ans += "#" + "." * less
	if r != last:
		ans += "\n"

print(ans)
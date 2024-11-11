a, b, c = map(int, input().split())
ans = 0

for i in range(a, b+1):
	if i % c == 0:
		ans += 1

print(ans)
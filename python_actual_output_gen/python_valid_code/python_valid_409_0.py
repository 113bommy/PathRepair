n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = 1
for i in a:
	if i > ans:
		ans += 1
print(ans + 1)

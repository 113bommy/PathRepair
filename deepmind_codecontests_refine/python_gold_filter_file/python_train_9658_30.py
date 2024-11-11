n = input()
a = list(map(int,input().split()))
ans = 0
for i in a[::2]:
	if i % 2 == 1:
		ans += 1
print(ans)
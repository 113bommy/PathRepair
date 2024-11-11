n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(0,n,2):
	if a[i]&1:
	ans += 1
print(ans)
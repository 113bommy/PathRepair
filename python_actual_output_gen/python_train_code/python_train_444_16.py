b, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
for i in range(k-1):
	ans += (a[i]%2) * (k%2)
ans += a[-1]%2
if ans%2 == 0:
	print("even")
else:
	print("odd")
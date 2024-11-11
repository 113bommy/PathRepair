n = int(input())
a = list(map(int, input().split()))
ans = 0
a.sort()

for i in range(n//2):
	print(a[i], a[n - i - 1])
	ans += (a[i] + a[n - i - 1])**2
	#print(ans)
print(ans)
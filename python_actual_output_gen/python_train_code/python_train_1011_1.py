n = int(input())
a = [0,0] + list(map(int, input().split()))
c = [0] + list(map(int,input().split()))
ans = 1

for i in range(2,n+1):
	if c[i] != c[a[i]]:
		ans += 1
print(ans + 1)

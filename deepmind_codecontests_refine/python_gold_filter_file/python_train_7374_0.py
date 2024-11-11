N = int(input())
ans = 0
for i in range(N):
	j,k = map(int,input().split())
	ans += k - j + 1
print(ans)
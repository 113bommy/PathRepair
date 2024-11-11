N = int(input())
X = list(map(int,input().split()))

for i in range(N):
	X[i] -= (i+1)

X.sort()
ans = 0
for i in range(N):
	ans += abs(X[i]-X[N//2])

print(ans)
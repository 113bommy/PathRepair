# def makelist(n, m):
# 	return [[0 for i in range(m)] for j in range(n)]

n = int(input())
A = [0]*N
for i in range(N):
	A[i] = int(input())

ans = A[0] - 1
A[0] = 1

cnt = 1
# yobi = 1

for i in range(1, N):
	now = A[i]

	if now > cnt:
		if now == cnt + 1: ## 0 ni nattyau
			cnt += 1
		else: ## now >= cnt + 2
			ans += now // (cnt + 1)
			if now % (cnt + 1) == 0:
				ans -= 1

print(ans)

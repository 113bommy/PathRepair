A, B, K = map(int, input().split())
ans = list(set(range(A, A+K)) | set(range(B-K, B)))
ans.sort()
for i in ans:
	if A <= i <= B:
		print(i)
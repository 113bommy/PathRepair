N, D = map(int, input().split())
A = list(map(int, input().split()))
sum = 0
for i in range(1, N):
	if A[i-1] <= A[i]:
		times = (A[i]-A[i-1])//D + 1
		A[i] += D*times
		sum += times
print(sum)
N, K = map(int, input().split())
A = list(map(int, input().split()))
k = 0
for i in range(N-K+1):
	if i>0:
		K_sum = K_sum-A[i-1]+A[i+K-1]
		K_sum0 = max(0, K_sum)
		K_pos = K_pos-max(0, A[i-1])+max(0, A[i+K-1])
	else:
		K_sum = sum(A[i:i+K])
		K_sum0 = max(0, K_sum)
		K_pos = sum(map(lambda x:max(0, x), A[i:i+K]))
	loss = K_pos-K_sum
	if i==0:
		loss_min = loss
	if loss<loss_min:
		k = i
		loss_min = loss
K_sum_result = max(0, sum(A[k:k+K]))
result = K_sum_result + sum(map(lambda x:max(0, x), A[:k]+A[k+K:]))
print(result)

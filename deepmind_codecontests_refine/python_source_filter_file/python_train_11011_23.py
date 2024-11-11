N,K = list(map(int, input().split()))
A = list(map(int, input().split()))

from itertools import accumulate
    
for _ in range(K):
	ans=[0]*(N+1)
    for i,a in enumerate(A):
        ans[max(0,i-a)]+=1
        ans[min(i+a+1,N)]-=1
    A = list(accumulate(ans))[:-1]
    if all(i == N for i in A):
        break
print(*A)
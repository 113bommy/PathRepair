import math
n, k, M, D = map(int,input().strip().split())

ans = 0

for d in range(1,D+1):

	x = min(M, n//((d-1)*k+1))
	if x == 0:
		continue
	real_d = ( n//x + k - 1) // k
	if real_d ==d:
		continue 

	gets = x * d
	ans = max(ans,gets)

print(ans)
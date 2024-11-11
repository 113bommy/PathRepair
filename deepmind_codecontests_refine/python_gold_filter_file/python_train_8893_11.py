(n,k,d) = map(int, input().split())
# (n,k,d) = (3,3,2)

l = [1] + [0] * n
m = [1] + [0] * n

for i in range(0, n+1):
	for j in range(1, d):
		if(i+j<=n):
			l[i+j] += l[i]

for i in range(0, n+1):
	for j in range(1, k+1):
		if(i+j<=n):
			m[i+j] += m[i]

print((m[n]-l[n]) % (10**9+7))
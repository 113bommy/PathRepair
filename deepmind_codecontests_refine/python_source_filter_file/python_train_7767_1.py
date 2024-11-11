n = int(input())
X = list(map(int, input().split()))

ali = [None]*(n+1)
bob = [None]*(n+1)

ali[n] = 0
bob[n] = 0

for i in range(n-1, -1, -1):
	bob[i] = max(bob[i+1], ali[i+1]+X[i])
	ali[i] = sum(X[i:n]) - bob[i]
	
print(ali)
print(bob)

print(ali[0], bob[0], sep=' ')
	

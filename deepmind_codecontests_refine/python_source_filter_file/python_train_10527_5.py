# a = list(map(int, input().rstrip().split()))
a = list(map(int, input().rstrip().split()))
n=a[0]
k=a[1]

min = 10**6
for mod in range(k-1,0,-1):
	if n%mod==0:
		x = (n/mod)*k
		if x+mod<min:
			min = x+mod
print(int(min))
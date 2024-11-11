n, m = map(int,input().split())
a = [int(input()) for i in range(m)]

p,q=(0,1)
#累積和っぽい考え
for i in range(1, n+1):
	p,q = q,(p+q)*(not i in a)
print(q%(10**9+7))
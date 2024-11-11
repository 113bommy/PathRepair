import sys

n, m = map(int, input().split())

a = list(map(int, input().split()))

k = list(map(int, input().split()))

c = 0
s = sum(k)

if m==1:
	if a.count(1)==k[0] or k[0] in a:
		print("YES")
	else:
		print("NO")
	sys.exit(0)

for i in range(n):
		
	if i+s-1<=n-1:
		k0 = [0]*m
		for j in a[i:i+s]:
			k0[j-1]+=1
	

		if k0==k:
			print("YES")
			sys.exit(0)

print("NO")
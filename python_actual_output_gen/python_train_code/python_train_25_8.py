n = input()
n = int(n)


k = input()

k = k.strip().split()
k = list(map(int,k))

l1 = [x for x in k if x<((10**6)/2)]
l2 = [x for x in k if x>=((10**6)/2)]

if not l1:
	p = 0
else:
	p = max(l1)-1	
if not l2:
	q = 0
else:
	q = 10**6 - min(l2)
	# print(q)
print(max(p,q))
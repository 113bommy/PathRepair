import math
n = int(input())
e = math.floor(math.log2(n))
m = pow(2,e)
j = 1
k=e
res = []
nq = 0
while k>0:
	for i in range(m//2):
		jpow = pow(2,j)
		jpowmin = pow(2,j-1)
		p = min(jpow*(i//jpowmin)+1+0+(i%jpowmin), n)
		q = min(jpow*(i//jpowmin)+1+jpowmin+(i%jpowmin), n)
		res.append(str(p)+' '+str(q))
		nq += 1
	j += 1
	k -= 1
if m!=n:
	j = 1
	k=e
	d = n-m
	while k>0:
		for i in range(m//2):
			jpow = pow(2,j)
			jpowmin = pow(2,j-1)
			p = jpow*(i//jpowmin)+1+0+(i%jpowmin)+d
			q = jpow*(i//jpowmin)+1+jpowmin+(i%jpowmin)+d
			res.append(str(p)+' '+str(q))
			nq += 1
		j += 1
		k -= 1
print(nq)
for i in range(len(res)):
		print(res[i])
n,m = [int(z) for z in input().split()]
dsf = 0
for _ in [0]*n:
	v = [int(z) for z in input().split()]
	if(v[0]<=dsf):
		dsf = v[1]
	if (dsf >= m):
		print('YES')
		exit(0)
if(dsf >= m):
	print('YES')
else:
	print('NO')

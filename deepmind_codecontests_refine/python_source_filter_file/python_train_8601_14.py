import math
k,p = map(int,input().strip().split(' '))
sm = 0
for i in range(1,k+1):
	ds = str(i)
	vl = i
	for j in range(len(ds)-1,-1,-1):
		vl =vl*10  + int(ds[j])
		print(vl)
	sm = (sm + vl)%p

print(sm)


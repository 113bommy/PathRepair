# from debug import debug
inf = int(1e8)

n, m = map(int, input().split())

x = [6*(i+1) for i in range(m+n)]

mt, mth = 2*n, 3*m
for i in x:
	t = 2*max(0, (mt-i)//2)
	th = 3*max(0, (mth-i)//2)
	if t == 0 or th == 0:
		break
	if th<t:
		mth+=3
	else:
		mt+=2

print(max(mth, mt))


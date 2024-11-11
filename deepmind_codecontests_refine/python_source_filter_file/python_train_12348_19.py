n=int(input())
t=[int(x) for x in input().split()]
t.sort()
t1=t[:n]
t2=t[n:2*n]
if t1[0]<t2[0]:
	print('YES')
else:
	print('NO')
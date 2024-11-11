'''input
2 2 2 1
'''
from sys import stdin,stdout
read = lambda : map(int,stdin.readline().split())
I = lambda: stdin.readline()

a,b,c,d = read()
ind = 0 if a+c<b+d else 1
res = [0 for i in range(a)] + [2 for i in range(b)]
for i in range(b):
	res.insert(ind,1)
	ind += 2
for j in range(d):
	res.insert(ind,3)
	ind += 2
for i in range(1,len(res)):
	if abs(res[i]-res[i-1])!=1:
		print('NO')
		break
else:
	print('YES')
	print(*res)

#still don't understand
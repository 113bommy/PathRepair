import sys
LI=lambda:list(map(int, sys.stdin.readline().strip('\n').split()))
MI=lambda:map(int, sys.stdin.readline().strip('\n').split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline().strip('\n'))

for _ in range(II()):
	n=II()
	a=SI()
	rc=a.count('R')
	if rc==0 or rc==n:
		print(n//3+(n%3!=0))
		continue
	i=a.index('L')
	while a[i]=='L':
		i=i+1 if i<n-1 else 0
	ans, c, j=0, 1, i+1 if i<n-1 else 0
	while j!=i:
		if a[j]==a[j-1 if j else n-1]:
			c+=1
		else:
			ans+=c//3
			c=1
		j=j+1 if j<n-1 else 0
	ans+=c//3
	print(ans)
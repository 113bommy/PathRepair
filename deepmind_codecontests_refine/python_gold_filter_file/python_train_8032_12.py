n,m=list(map(int,input().split()))
l=[]
for _ in range(n):
    a=input()
    l.append(a)
f=0
ind=()
for i in range(1,n-1):
	for j in range(1,m-1):
		if l[i][j]=='*':
			if l[i-1][j]=='*' and l[i][j-1]=='*' and l[i+1][j]=='*' and l[i][j+1]=='*':
				if f==0:
					f=1
					ind=(i,j)
				else:
					f=0
					break
if f==1:
	top=(0,0)
	bottom=(0,0)
	left=(0,0)
	right=(0,0)
	for i in range(ind[0]-1,-1,-1):
		if l[i][ind[1]]=='*':
			top=(i,ind[1])
		else:
		    break
	for i in range(ind[0]+1,n):
		if l[i][ind[1]]=='*':
			bottom=(i,ind[1])
		else:
		    break
	for j in range(ind[1]-1,-1,-1):
		if l[ind[0]][j]=='*':
			left=(ind[0],j)
		else:
		    break
	for j in range(ind[1]+1,m):
		if l[ind[0]][j]=='*':
			right=(ind[0],j)
		else:
		    break
	for i in range(n):
		for j in range(m):
			if j==top[1] and i>=top[0] and i<=bottom[0]:
				continue
			if i==left[0] and j>=left[1] and j<=right[1]:
				continue
			if l[i][j]=='*':
				f=0
				break
if f==0:
	print("NO")
else:
	print("YES")

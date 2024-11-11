r,c = map(int,input().split())
l1 = [input() for i in range(r)]
l,c1,c2 = [],0,0
for i in range(r):
	if 'S' in l1[i]:
		c1+=1
for j in range(c):
	for i in range(r):
		if l1[i][j]=='S':
			c2+=1
			break
print(4*(r-c1)+3*(c-c2)-(r-c1),(c-c2))

x = int(input())
l=list()
for i in range(x): 
	l.append(list(input()))
	
flag='YES'
for i in range(x):
	for j in range(x):
		if i==j:
			if l[i][i]!=l[1][0] or l[i][x-i-1]!=l[0][0]:
				flag='NO'

		elif i!=j and j!=x-i-1:
			if l[i][j]!=l[0][1] or l[i][j]==l[0][0]:
				flag='NO'

print(flag)
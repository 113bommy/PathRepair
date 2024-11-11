n,m=map(int,input().split())
l=[]
for i in range(n):
	l.append(list(input()))
c=0
t=0
for j in range(n):
	for k in range(m):
		if(l[j][k]=='W'):
			if(-1<(j-1)<n):
				if(l[j-1][k]=='P'):
					c=c+1
					l[j-1][k]='.'
					l[j][k]='.'
			if(-1<(j+1)<n):
				if(l[j][k]=='W'):
					if(l[j+1][k]=='P'):
						c=c+1
						l[j+1][k]='.'
						l[j][k]='.'
			if(-1<(k-1)<m):
				if(l[j][k]=='W'):
					if(l[j][k-1]=='P'):
						c=c+1
						l[j][k-1]='.'
						l[j][k]='.'

			if(1<(k+1)<m):
				if(l[j][k]=='W'):
					if(l[j][k+1]=='P'):
						c=c+1
						l[j][k+1]='.'
						l[j][k]='.'
print(c)
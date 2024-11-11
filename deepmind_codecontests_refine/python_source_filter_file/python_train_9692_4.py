# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("outp.out",'w')
n,m=map(int,input().split())
a=[input() for i in range(n)]
l=[]
for i in range(n):
	if 'B' in a[i]:
		x=[]
		j=0
		while j<m:
			if a[i][j]=='B':
				x.append((i,j))
			j+=1	
		l.append(x)
print(l)		
p=int((l[-1][0][0]+l[0][0][0])/2)
q=int((l[-1][-1][1]+l[-1][0][1])/2)
print(p+1,q+1)
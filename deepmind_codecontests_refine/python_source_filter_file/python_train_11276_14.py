import sys
input=sys.stdin.readline
n,m,k=map(int,input().strip().split(" "))
#s=input().strip()
#n=int(input().strip())
#a=list(map(int,input().strip().split(" ")))
lr=[]
for i in range(n):
	lr.append([100000001]+list(map(int,input().strip().split(" ")))+[100000001])
ud=[[100000001]*m]
for i in range(n-1):
	ud.append(list(map(int,input().strip().split(" "))))
ud.append([100000001]*m)
o=[[1000000001]*(m+2)]
from copy import deepcopy
if k%2:
	for i in range(n):
		sys.stdout.write(" ".join(["-1"]*m)+"\n")
	sys.exit()
for _ in range(n):
	oo=[100000001]
	for _ in range(m):
		oo.append(0)
	oo.append(100000001)
	o.append(oo)
o.append([100000001]*(m+2))
for _ in range(k//2):
	oo=deepcopy(o)
	for i in range(1,n+1):
		for j in range(1,m+1):
			oo[i][j]=min(lr[i-1][j-1]+o[i][j],lr[i-1][j]+o[i][j+1],ud[i-1][j-1]+o[i-1][j],ud[i][j-1]+o[i+1][j])
	o=deepcopy(oo)
for i in o[1:n+1]:
	sys.stdout.write(" ".join(map(str,[j*2 for j in i[1:m+1]]))+"\n")

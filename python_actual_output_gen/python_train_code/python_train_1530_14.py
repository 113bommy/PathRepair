# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output2.out","w")
N,M=map(int,input().split())
L,X,Y=[],[],[]
for i in range(N):
	L.append(list(input()))
for i in range(N):
	for j in range(M):
		if L[i][j]=='*':
			X.append(i+1)
			Y.append(j+1)
if X[0]!=X[1]:
	if Y[0]==Y[2]:		
		print(X[0],Y[1])
	else:
		print(X[0],Y[2])
else:
	if Y[0]==Y[2]:
		print(X[2],Y[1])
	else:
		print(X[2],Y[2])
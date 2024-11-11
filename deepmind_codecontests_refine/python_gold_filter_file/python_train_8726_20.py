H,W,D=list(map(int,input().split()))
X=[(0,0) for i in range(H*W+1)]

for i in range(1,H+1):
	A=list(map(int,input().split()))
	for idx,a in enumerate(A):
		X[a]=(i,idx+1)

Q=int(input())
L=[]
R=[]
S=[0]*(H*W+1)

for i in range(Q):
	l,r=list(map(int,input().split()))
	L.append(l)
	R.append(r)

for i in range(D+1,H*W+1):
	S[i]=S[i-D]+abs(X[i][0]-X[i-D][0])+abs(X[i][1]-X[i-D][1])

for i in range(Q):
	print(S[R[i]]-S[L[i]])
	
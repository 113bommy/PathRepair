n,w=map(int,input().split())
A=tuple(map(int,input().split()))

S=[A[0]]
for i in range(n-1):
	S.append(A[i+1]+S[-1])

m,M=int(10e6),0
for i in S:
	M=max(i,M)
	m=min(i,m)

if -m>w or M>w or M-m>w:
	print(0)
	exit(0)

if m>=0:
	print(w-M+1)
else:
	print(w+m+1)

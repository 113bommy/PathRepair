from collections import deque
H,W,K=map(int,input().split())
A=[list(input())for _ in range(H)]
for i in range(W):
	if"S"in A[i]:y,x=(i,A[i].index("S"))
d=1e9
Q=deque([(1,y,x)])
while Q:
	c,i,j=Q.popleft()
	d=min(d,i,j,H-i-1,W-j-1)
	if c>K:continue
	for h,w in((i+1,j),(i,j+1),(i-1,j),(i,j-1)):
		if 0<=h<H and 0<=w<W and A[h][w]==".":
			A[h][w]=""
			Q+=[(c+1,h,w)]
print(1-(-d//K))
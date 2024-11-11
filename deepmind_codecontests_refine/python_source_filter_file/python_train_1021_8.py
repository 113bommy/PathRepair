H,W=map(int,input().split())
A=[input() for i in range(H)]

f=True
for i in range(H):
	for j in range(W):
		if A[i][j]=='#':
			f=False
			for a,b in [(-1,0),(1,0),(0,1),(0,-1)]:
				if 0<=i+a<H and 0<=j+b<W:
					if A[i+a][j+b]=='#':f=True
			if not(f):break

print('Yes' if f else 'No')
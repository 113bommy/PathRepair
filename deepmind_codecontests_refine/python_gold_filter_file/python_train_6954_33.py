h,w=map(int,input().split())
s=[input()for _ in range(h)]

yoko=[[0]*2005 for _ in range(2005)]
tate=[[0]*2005 for _ in range(2005)]

for i in range(h):
	for j in range(w):
		if s[i][j] == ".":
			yoko[i][j]+=1
			if j>0:
				yoko[i][j]+=yoko[i][j-1]
	for j in range(w-2,-1,-1):
		yoko[i][j] = max(yoko[i][j],yoko[i][j+1]) if yoko[i][j] else 0

for j in range(w):
	for i in range(h):
		if s[i][j] == ".":
			tate[i][j]+=1
			if i>0:
				tate[i][j]+=tate[i-1][j]
	for i in range(h-2,-1,-1):
		tate[i][j] = max(tate[i][j],tate[i+1][j])  if tate[i][j] else 0

ans = 0
for i in range(h):
	for j in range(w):
		ans = max(ans,yoko[i][j]+tate[i][j]-1)
print(ans)
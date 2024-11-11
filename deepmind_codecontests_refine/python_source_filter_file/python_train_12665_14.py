from collections import Counter
n,k=map(int,input().split())
v=[input().strip() for _ in range(n)]
s=Counter()
for i in range(n):
	for j in range(n):
		if all(x<n and v[x][j]=='.' for x in range(i,i+k)): s.update((x+1,j+1) for x in range(i,i+k))
		if all(x<n and v[i][x]=='.' for x in range(j,j+k)): s.update((i+1,x+1) for x in range(j,j+k))
if len(s)==0: s[(0,0)]+=1
print(*s.most_common(1)[0][0])
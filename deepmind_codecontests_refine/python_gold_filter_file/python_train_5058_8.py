n = int(input())
a = [[int(x) for x in input().split()] for _ in range(n)]
m = int(input())
b = [[int(x) for x in input().split()] for _ in range(m)]

ans = 0
R,L = 1e9,0
for i in range(n):
	R = min(R,a[i][1])
for i in range(m):
	L = max(L,b[i][0])
ans = max(ans,L-R)
R,L = 1e9,0
for i in range(m):
	R = min(R,b[i][1])
for i in range(n):
	L = max(L,a[i][0])
ans = max(ans,L-R)

print(ans)	

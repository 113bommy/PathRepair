n = int(input())
c = []
s=0
for i in range(n):
		c.append(input().split())
for i in range(n):
	s+=int(c[i][i])+int(c[i][n-i-1])+int(c[(n//2)][i])+int(c[i][(n//2)])
print(s)
s-=3*int(c[(n//2)][(n//2)])	
print(s)
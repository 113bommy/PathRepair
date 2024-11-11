n,skip = map(int,input().split())
c = 0
s = [[1,1]]

for i in range(n):
	a,b = map(int,input().split())
	b += 1
	s.append([a,b])

for i in range(n-1):
	if (s[i+1][0]-s[i][1])>=skip:
		c+=(s[i+1][0]-s[i][1])%skip
	else:
		c+=s[i+1][0]-s[i][1]

for i in range(1,n+1):
	c+= s[i][1]-s[i][0]


print(c)
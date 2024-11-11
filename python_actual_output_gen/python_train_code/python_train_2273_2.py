n = int(input())
s = []
c = 0
for i in range(n):
	s.append(input())

print(s)

for i in range(1,n-1):
	for j in range(1,n-1):
		if s[i][j]==s[i-1][j-1]==s[i-1][j+1]==s[i+1][j-1]==s[i+1][j+1]=="X":
			c+=1
print(c)
n = int(input())
c = True
s = []
for i in range(n):
	a,b = sorted(map(int,input().split()))
	s.append((a,b))


for i in range(n-1):
	if s[i][1]<s[i+1][0]:
		c = False
		break
	elif s[i][1]<s[i+1][1]:
		s[i+1] = [s[i+1][1],s[i+1][0]]

if c:
	print("YES")
else:
	print("NO")


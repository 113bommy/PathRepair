n = int(input())
s = [int(i) for i in input().split()]
c = True
cnt = s[1]-s[0]

for i in range(n-1):
	if s[i+1]-s[i]!=cnt:
		c = False
		break
print(c)
if c:
	print(s[-1]+cnt)
else:
	print(s[-1])
n, x, y=map(int, input().split())
a='1'+input()
c=0
for i in range(n):
	if a[i]=='0' and a[i-1]=='1':
		c+=1
print(min(c*y, max(0, y+(c-1)*x)))
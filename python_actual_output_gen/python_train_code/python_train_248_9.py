n=int(input())
s=['o' for i in range(n)]
a,b=1,1
while a<n:
	s[a-1]='O'
	a,b=a+b,a
for m in s:
	print(m,end='')
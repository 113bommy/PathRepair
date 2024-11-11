n=int(input())
s=0
for i in range(1,n):
	s+=(n-i)*i
print(s+n)
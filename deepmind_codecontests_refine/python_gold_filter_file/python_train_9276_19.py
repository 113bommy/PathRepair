n=int(input())
s=input().split()[1:]
s=set(s)
for i in range(n-1):
	s1=input().split()[1:]
	s1=set(s1)
	s=s & s1
print(*list(s))
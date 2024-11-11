from sys import stdin
input=stdin.readline
for _ in range(int(input())):
	n=int(input());s=0;p=0
	for i in map(int,input().split()):
		s+=i
		p^=i
	if s==p*2:print(0,"\n")
	else:
		print(n+2)
		print(p,s+p)
		
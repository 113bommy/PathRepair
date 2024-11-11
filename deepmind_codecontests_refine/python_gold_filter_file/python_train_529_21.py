# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("outp.out",'w')
n,l,a=map(int,input().split())
s=0
p=0
for i in range(n):
	t,x=map(int,input().split())
	p+=(t-s)//a
	s=t+x
p+=(l-s)//a
print(p)

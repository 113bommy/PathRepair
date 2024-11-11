# import sys 
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out.out",'w')
n=int(input())
a=list(map(int,input().split()))
x=a.count(0)
y=a.count(5)//9
if x:
	s="5"*(9*y)+"0"*x
	print(int(s))
else:
	print(-1)

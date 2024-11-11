# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output1.out","w")
T=int(input())
while T:
	s,a,b,c=map(int,input().split())
	print(int(s/c)+int(s/a)*b)
	T-=1
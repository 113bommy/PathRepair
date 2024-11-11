# import sys 
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out.out",'w')
n=int(input())
l=[]
for i in range(n*n):
	h,v=map(int,input().split())
	if h not in l and v not in l:
		print(i+1,end=" ")
		l.append(h)
		l.append(v)


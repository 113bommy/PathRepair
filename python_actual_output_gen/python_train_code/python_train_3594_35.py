# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")

l=list(map(int,input().split()))
k=l[0]
n=l[1]
w=l[2]
rs=0
for i in range(1,w+1):
	rs+=(k*i)
print(rs-n)	

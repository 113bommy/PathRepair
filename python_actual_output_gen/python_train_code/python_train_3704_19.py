# import sys 
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output2.out","w")
n,m,k=map(int,input().split())
if n>m:
	n,m=m,n
if k>m-n:
	print(m*2+(k-(m-n))-(k-m+n)%2)
elif k<m-n:
	print((n+k)*2)
else:
	print("0")
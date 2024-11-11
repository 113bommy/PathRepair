# import sys 
# sys.stdin=open("input1.in","r")
# sys.stdout=open("OUTPUX.out","w")
N=int(input())
X,Y=map(int,input().split())
dist1=max(X-1,Y-1)
dist2=max(N-X,N-Y)
if dist1>=dist2:
	print("White")
else:
	print("Black")
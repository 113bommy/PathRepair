# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
A=int(input())
B=int(input())
C=int(input())
for i in range(A,-1,-1):
	if B>2*i and C>4*i:
		print(7*i)
		break

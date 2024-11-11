# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
n=int(input())
L=list(map(int,input().split()))
L.sort()
if n%2==0:
	print(L[int(n/2)-1])
else:
	print(L[int((n+1)/2)])
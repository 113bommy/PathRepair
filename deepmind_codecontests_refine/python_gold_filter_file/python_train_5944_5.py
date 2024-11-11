# import sys
# sys.stdin=open("input.in","r")
# # sys.stdout=open("output.out","w")
X=int(input())
L=list(map(int,input().split()))
for i in range(len(L)):
	if(L[i]%2==0):
		L[i]=L[i]-1
print(*L)
# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
x=int(input())
count=0
L=list(map(int,input().split()))
for i in range(x):
	count+=max(L)-L[i]
print(count)

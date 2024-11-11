# import sys
# sys.stdin=open("input.in","r")
n=int(input())
c=0
for i in range(n):
	a=list(map(str,input().split()))
	if int(a[1])>2400 and int(a[2])>int(a[1]):
		c+=1
if(c>=1):
	print("YES")
else:
	print("NO")
# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
l,r,a=map(int,input().split())
if l>r:
	if r+a==l:
		print(l+r+a)
	elif r+a>l:
		c=r+a-l
		print(2*(l+c//2))
	else:
		print(2*(r+a))
elif l<r:
	if l+a==r:
		print(l+r+a)
	elif l+a>r:
		c=l+a-r
		print(2*(l+c//2))
	else:
		print(2*(l+a))
else:
	print(2*(l+a//2))						
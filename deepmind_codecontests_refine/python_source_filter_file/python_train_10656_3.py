# your code goes here
n=int(input())
left=list()
right=list()
for index in range(0,n):
	l,r=map(int,input().split())
	left.append(l)
	right.append(r)
minl=min(left)
maxr=max(right)
found=-1
for index in range(0,n):
	if(left[index]==minl and right[index]==maxr):
		found=index
		break
if(found==-1):
	print(found+1)
else:
	print(found+1)
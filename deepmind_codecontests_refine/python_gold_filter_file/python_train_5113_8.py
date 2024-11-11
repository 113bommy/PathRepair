# your code goes here
# your code goes here
n,m=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
f=0
if l1[0]==0:
	print("NO")

elif l1[m-1]==1:
	print("YES")
elif l2[m-1]==0:
	print("NO")
else:
	for i in range(m-1,n):
		f=2
		if l1[i]==1 and l2[i]==1:
			print("YES")
			f=1
			break
if f==2:
	print("NO")
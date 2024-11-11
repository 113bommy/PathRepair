def check(num):
	r=R[n-1]-(R[num-1])
	l=L[n-1]-(L[num-1])
	u=U[n-1]-(U[num-1])
	d=D[n-1]-(D[num-1])
	if abs(x-(r-l))+abs(y-(u-d))<=num:
		return True
	for i in range(num,n):
		r=R[n-1]-(R[i]-R[i-num])
		l=L[n-1]-(L[i]-L[i-num])
		u=U[n-1]-(U[i]-U[i-num])
		d=D[n-1]-(D[i]-D[i-num])
		if abs(x-(r-l))+abs(y-(u-d))<=num:
			return True
	return False

n=int(input())
s=input()
x,y=map(int,input().split())
R,L,U,D={},{},{},{}
for i in range(n):
	R[i]=R[i-1] if i>0 else 0
	L[i]=L[i-1] if i>0 else 0
	U[i]=U[i-1] if i>0 else 0
	D[i]=D[i-1] if i>0 else 0
	if s[i]=="R":
		R[i]+=1
	elif s[i]=="L":
		L[i]+=1
	elif s[i]=="U":
		U[i]+=1
	else:
		D[i]+=1
if (abs(x-(R[n-1])+L[n-1]))+abs(y-(U[n-1]-D[n-1]))==0:
	print (0)
	exit(0)
if (abs(x)+abs(y))%2!=n%2:
	print (-1)
	exit(0)
low=1
high=n
while (low<high):
	mid=(low+high)//2
	if check(mid):
		high=mid-1
	else:
		low=mid+1
# print(low)
if check(low):
	print (low)
else:
	if low==n:
		print (-1)
		exit(0)
	print (low+1)
import math
n=int(input())
arr=list(map(int,input().split()))
if n==1:
	print(0)
	exit()
even=[0]*(n)
odd=[0]*(n)
even[0]=0
odd[0]=arr[0]
a=1
b=1
for i in range(1,n):
	if i%2==0:
		odd[a]=arr[i]+odd[a-1]
		even[b]=even[b-1]
	else:
		even[b]=arr[i]+even[b-1]
		odd[a]=odd[a-1]
	a+=1
	b+=1
# print(even)
# print(odd)
# print(sum(arr))
ans=0
for i in range(n):
	# if i%2==0:
	# 	#odd
	xx=0
	if i>0:
		xx+=odd[i-1]
	# if i+1<n:
	xx+=even[n-1]-even[i]

	yy=0
	if i>0:
		yy+=even[i-1]
	# if i+1<n:
	yy+=odd[n-1]-odd[i]
	# print(i,xx,yy)
	if xx==yy:
		ans+=1
	# else:
print(ans)
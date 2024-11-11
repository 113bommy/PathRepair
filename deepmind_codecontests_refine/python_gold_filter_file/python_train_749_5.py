from math import *
# from sys import stdin,stdout

def binarySearch(arr,x,i):
	l=i
	r=len(arr)-1 
	while l <= r: 
		mid = (l + r)//2; 
		if arr[mid] == x: 
			return mid 
		elif arr[mid] < x: 
			l = mid + 1
		else: 
			r = mid - 1
	return -1

def js(arr,x):
	l=0
	r=len(arr)-1
	ans=-1
	while(l<=r):
		m=(l+r)//2
		if(arr[m]<=x):
			ans=m
			l=m+1
		else:
			r=m-1
	return ans

def jg(arr,x):
	l=0
	r=len(arr)-1
	ans=-1
	while(l<=r):
		m=(l+r)//2
		if(arr[m]>=x):
			ans=m
			r=m-1
		else:
			l=m+1
	return ans

# def ceil(a,b):
# 	if a%b == 0:
# 		return int(a/b)
# 	else:
# 		return (a//b + 1)

def simple(s,n):
	a=-1
	for i in range(n):
		if(s[i]=='('):
			a=i
			break
	b=-1
	for i in range(a,n):
		if(s[i]==')'):
			b=i
			break

	if(a<b and a!=-1):
		return False
	return True

s=input()
s=list(s)
n=len(s)
ans=[]
while(simple(s,n)==False):
	# print("asdf")
	x=0
	y=n-1
	r=[]
	while(x<y):
		if(s[x]=='(' and s[y]==')'):
			s[x]=-1
			s[y]=-1
			r.append(x+1)
			r.append(y+1)
			x+=1
			y-=1
		if(s[x]!='('):
			x+=1
		if(s[y]!=')'):
			y-=1
	if(r!=[]):
		r.sort()
		ans.append(r)
print(len(ans))
for i in range(len(ans)):
	print(len(ans[i]))
	print(*ans[i])
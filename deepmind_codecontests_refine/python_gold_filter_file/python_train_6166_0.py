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

def ceil(a,b):
	if a%b == 0:
		return int(a/b)
	else:
		return (a//b + 1)


n,m=map(int,input().split())
s=[]
for i in range(n):
	ss=input()
	s.append(ss)
s.sort()
h=[0]*n
ans=[]
ans1=[]
# print(s)
for i in range(n):
	ind=binarySearch(s,s[i][::-1],i+1)
	if(ind!=-1 and h[ind]!=1 and h[i]!=1):
		ans.append(s[i])
		ans1.append(s[i][::-1])
		h[i]=1
		h[ind]=1
ans2=[]
for i in range(n):
	if(h[i]==0 and s[i]==s[i][::-1]):
		ans2.append(s[i])
# print(ans)
# print(ans1,ans2)

if(len(ans)>0):
	if(len(ans2)>0):
		rslt="".join(ans)+ ans2[0]+"".join(ans1[::-1])
		print(len(rslt))
		print(rslt)
	else:
		rslt="".join(ans)+"".join(ans1[::-1])
		print(len(rslt))
		print(rslt)
elif(len(ans)==0):
	if(len(ans2)>0):
		print(m)
		print(ans2[0])
	else:
		print(0)
else:
	rslt="".join(ans)+"".join(ans1[::-1])
	print(len(rslt))
	print(rslt)





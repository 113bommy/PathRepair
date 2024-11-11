from math import log,ceil
n,k=map(int,input().split())
p=ceil(log(k+2,2))-1
m=(2**(p+1)-2-k)
ans=((n+m-(2**p-1))//(2**p))*2
ans2=ans+1
if 2**(p-1)-1+min(n,ans2*2**(p-1)+2**(p-1)-1)-ans2*2**(p-1)+1>=k:
	ans=ans2
print(max(ans,1))
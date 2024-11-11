from math import  gcd
def get_mex(a):
	for i in range(len(a)):
		if a[i]==0:
			return i
def f(a):
	cnt=[0]*(len(a)+1)
	for i in a:
		cnt[i]+=1
	ans=[]
	mex=get_mex(cnt)
	ll=0
	while a!=sorted(a):
		if mex<len(a):
			cnt[a[mex]]-=1
			cnt[mex]+=1
			a[mex]=mex
			ans.append(mex+1)
			mex=get_mex(cnt)
		else:
			for i in range(len(a)):
				if a[i]!=i:
					cnt[a[i]]-=1
					cnt[mex]+=1
					a[i]=mex
					ans.append(i)
					break
			mex=get_mex(cnt)
	print(len(ans))
	return ans

for i in range(int(input())):
	a=input().strip()
	lst=list(map(int,input().strip().split()))
	print(*f(lst))

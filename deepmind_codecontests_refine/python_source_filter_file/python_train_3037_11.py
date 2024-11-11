import sys
input = sys.stdin.readline
print = sys.stdout.write
dp={}
def f(l,r):
	n=r-l+1
	if n==1:return([0,s[l-1]])
	if n==2:
		m=s[l-1]+s[r-1]
		if m>=10:
			dp[(l,r)]=[1,m%10]
			return([1,m%10])
		dp[(l,r)]=[0,m]
		return([0,m])
	if (l,r) in dp.keys():return(dp[(l,r)])
	d1=f(l,l+n//2-1)
	d2=f(l+n//2,r)
	if d1[1]+d2[1]>=10:
		d=d1[0]+d2[0]+1
		c=(d1[1]+d2[1])%10
	else:
		d=d1[0]+d2[0]
		c=d1[1]+d2[1]
	dp[(l,r)]=[d,c]
	return([d,c])
 
 
n=int(input())
s=list(map(int,input().split()))
q=int(input())
for i in range(q):
	l,r=map(int,input().split())
	print(str(f(l,r)[0]))
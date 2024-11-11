n,k = map(int,input().split())
s = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]
e = []
cnt,ans,a = 0,0,0
l,r = 0,min(k,n)
for i in range(min(k+1,n)):
	if d[i]==0:
		cnt+=s[i]
for i in range(n):
	if d[i]==1:
		ans+=s[i]

a = cnt

while r<n:
	if d[r]==0:
		cnt+=s[r]
	if d[l]==0:
		cnt-=s[l]
	a = max(a,cnt)
	l+=1
	r+=1
print(ans+a)
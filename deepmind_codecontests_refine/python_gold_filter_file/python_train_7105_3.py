n = int(input())
a = list(map(int,input().split()))
if n==1:
	print (a[0])
	exit()

pref = [a[0],a[1]]
suff = [0]*n
suff[-1] = a[-1]
suff[-2] = a[-2]
for i in range(2,n):
	pref.append(pref[i-2]+a[i])
for i in range(n-3,-1,-1):
	suff[i] = suff[i+2]+a[i]

ans = pref[-1]
for i in range(n-1):
	ans = max(ans,pref[i]+suff[i+1])

print (ans)
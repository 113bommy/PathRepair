from sys import stdin
ip = stdin.readline
for _ in range(int(ip())):
	n = int(ip())
	a = [ int(i)-1 for i in ip().split()]
	cnt = [0]*n
	ans = [0]*n
	for i in a: cnt[i]+=1
	ans[0]=0 if cnt.count(0)>0 else 1
	ans[n-1]=int(cnt[0]>0)
	l, r= 0, n-1
	for i in range(1, n):
		j=i-1
		if cnt[j]==1 and cnt[i]:
			if a[l]==j: l+=1
			elif a[r]==j: r-=1
			else: break
			ans[n-i-1]=1
		else: break
	print(*ans, sep='')
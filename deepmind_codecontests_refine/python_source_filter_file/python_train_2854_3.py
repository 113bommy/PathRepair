n = int(input())
s = [int(i) for i in input().split()]+[-1]
d = 1

if n==1:
	print(d)

else:
	r = 2
	cnt = 0
	maxi = 2
	while r<=n:
		if s[r-1]+s[r-2]==s[r]:
			cnt+=1
		else:
			maxi = max(cnt,maxi+cnt)
			cnt = 0
		r+=1
	print(maxi)
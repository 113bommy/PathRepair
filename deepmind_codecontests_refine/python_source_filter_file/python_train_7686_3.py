##create with UTF-8

n = int( input() )
da=list(map(int, input(). split()))
li=[da[i]%(n+1) for i in range(n)]
su=0
ans=0
for i in range(n):
	su+=da[i]
for i in range(n):
	div=(n-1)-(da[i]%(n+1))
	now=0
	ju=True
	for j in range(n):
		if (n+1+div+da[j])%(n+1)==n:
			ju=False
			break
		now+=(n+1+div+da[j])%(n+1)
	if ju and su >= now:
		print(now)
		ans = max(ans,now)
print(su-ans)
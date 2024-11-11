n,k = map(str,input().split())
k = int(k)
a = n.count("0")
cnt = 0
ans = 0

if int(n)%(10**k)==0:
	print(0)

elif len(n)<=len(str(10**k)):
	print(len(n)-1)
else:
	i = len(n)-1
	while cnt<k:
		if n[i]!="0":
			ans+=1
		else:
			cnt+=1
		i-=1
	if ans+a==len(n):
		print(len(n)-1)
	else:
		print(ans)
	


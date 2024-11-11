n,s=map(int,input().split())
a=map(int,input().split())
upper=max(a)
su=sum(a)
if su-upper <= s:
	print("YES")
else:
	print("NO")
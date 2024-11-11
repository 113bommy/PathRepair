t = int(input())
for _ in range(t):
	b,p,f=list(map(int,input().split()))
	h,c=list(map(int,input().split()))
	ans=0
	if(c>h):
		ans+=c*(min(b//2, f))
		b-=(ans//c)*2
		ans+=h*(min(b//2,p))
	else:
		ans+=h*(min(b//2,p))
		b-=(ans//h)*2
		ans+=c*(min(b//2,f))
	print(ans)
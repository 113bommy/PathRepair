[n,m] = [int(x) for x in input().split()]
ac=[0]*(n+1)
wa=[0]*(n+1)
cnt_ac=0
cnt_wa=0
for i in range(m):
	p,s=input().split()
	p=int(p)
	if s=="AC":
		if	fac[p]==0:
			cnt_ac+=1
			cnt_wa+=wa[p]
			ac[p]=1
		
	else: 
		wa[p]+=1

print(int(cnt_ac),int(cnt_wa))
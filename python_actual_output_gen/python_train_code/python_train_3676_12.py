n=int(input())
s=input()
e,w=s.count('E'),s.count('W')
le,lw=0,0
ans=10**6
for c in s:
	if c=='E':
		e-=1
		ans=min(ans,e+lw)		
	else:
		lw+=1
print(ans)
t=int(input())
mod=998244353
for i3 in range(t):
	s=str(input())
	n=len(s)
	hash,hash2=0,0
	o=ord("a")
	ans=0
	a,b=0,n-1
	ma=0
	while s[a]==s[b] and b>a+2:
		a+=1
		b-=1
	a-=1
	b+=1
	goal=[a,b]
	for i in range(a+1,b):
		hash*=26
		hash+=ord(s[i])-o
		hash2+=(ord(s[i])-o)*pow(26,i-a-1,mod)
		hash%=mod
		hash2%=mod
		if hash==hash2 and ma<i-a: ma,goal=i-a,[i,b]
	hashb,hashb2=0,0
	for i in range(b-1,a,-1):
		hashb+=(ord(s[i])-o)*pow(26,b-1-i,mod)
		hashb2*=26
		hashb2+=ord(s[i])-o
		hashb%=mod
		hashb2%=mod
		if hashb==hashb2 and ma<b-a: ma,goal=b-i,[a,i]
	for i in range(goal[0]+1): print(s[i],end="")
	for i in range(goal[1],n): print(s[i],end="")
	print("")
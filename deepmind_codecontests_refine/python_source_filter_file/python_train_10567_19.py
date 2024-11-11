s=list(input())
d=len(s)
m=int(input())
for i in range(m):
	l,r,k=map(int,input().split())
	
	x=k%d
	
	if x:
		pre=s[l-1:r-x]
		post=s[r-x:r]
		
		s[l-1:r]=post+pre
		
print(*s,sep="")

	
		
		
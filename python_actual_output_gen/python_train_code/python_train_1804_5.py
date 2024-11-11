s=input()
n=len(s)
c,r,ans=0,0,0
for i in range(n):
	r+=int(s[i])
	c+=1
	if int(s[i])%3==0 or r==0 or c==3:
		ans+=1
		r,c=0,0
print(ans)
n,m=(map(int,input().split()))
s=input()
for i in range(m):  
	l,r,c1,c2=map(str,input().split())
	l=int(l)
	r=int(r)
	s=s[0:l-1]+s[l-1:r+1].replace(c1,c2)+s[r+1:n]
print(s)
_,s,*a=map(int,open(0).read().split())
c,i,*d=[0]*s*4
for a in a:
 for j in range(s,0,-1):d[a+j]+=d[j]
 d[a]-=~i;c+=d[s];i+=1
print(c%(998244353))
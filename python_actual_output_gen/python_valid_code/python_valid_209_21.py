n,p,k=map(int,input().strip().split())
lo=max(p-k,1)
hi=min(n,p+k)
ans=""
if lo>1:
	ans+="<<"
for i in range(lo,p):
	ans+=" "+str(i)
if p>1:
	ans+=" "
	ans+='('+str(p)+')'
for i in range(p+1,hi+1):
	ans+=" "+str(i)
if hi<n:
	ans+=">>"
print(ans)

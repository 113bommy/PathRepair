n,k=map(int,input().strip().split())
s=input().strip()
l=r=0
c=0
while r<n and s[r]=='1': r+=1
while c<k:
 while r<n and s[r]=='0':r+=1
 while r<n and s[r]=='1':r+=1
 if r==n:print(n);exit()
 c+=1
ans=r-l
while r<n:
 while l<n and s[l]=='1':l+=1
 while l<n and s[l]=='0':l+=1 
 while r<n and s[r]=='0':r+=1
 while r<n and s[r]=='1':r+=1
 ans=max(ans,r-l)
print(ans)

 


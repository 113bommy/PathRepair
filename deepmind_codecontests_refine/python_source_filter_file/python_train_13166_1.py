x=list(map(int,input().split()))
s=list(input().rstrip())
n=len(s)
cx=[0]*(n+1)
for i in range(1,n+1):
  cx[i]=x[ord(s[i-1])-ord("a")]
for i in range(1,n+1):
  cx[i]+=cx[i-1]
pos=[{} for i in range(26)]
ans=0
for i in range(n):
  ss=s[i]
  ans+=pos[ord(ss)-ord("a")].get(cx[i],0)
  pos[ord(ss)-ord("a")][cx[i+1]]=pos[ord(ss)-ord("a")].get(cx[i],0)+1
print(ans)
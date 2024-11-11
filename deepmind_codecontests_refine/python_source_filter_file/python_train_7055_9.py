N,M=map(int,input().split())
list=[0 for i in range(5*10**5+1)]
mod=10**9+7
list[0]=1
for i in range(len(list)-1):
  list[i+1]=list[i]*(i+1)%mod
def c(m,n):
  a=list[m]*pow(list[m-n],mod-2,mod)*pow(list[n],mod-2,mod)
  return a
def p(m,n):
  a=list[m]*pow(list[m-n],mod-2,mod)
  return a
ans=pow(p(M,N),2)
g=pow(list[M-N],mod-2,mod)
g2=pow(g,2,mod)
nn=list[N]
mm=list[M]
nmg=nn*mm*g2%mod
for i in range(1,N+1):
  ans+=nmg*pow(list[N-i],mod-2,mod)*pow(list[i],mod-2,mod)*list[M-i]*(-1)**i
  ans%=mod
print(ans)
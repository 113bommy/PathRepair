I=lambda:map(int,input().split());F=1e21;r=range;n,m=I();f=[-F,F];X=[0]+f;Y=X[:];R=(f,F),(f,-F),;H=(F,f),(-F,f),
for i in r(n):*a,c=I();R+=(a,c),;Y+=c,;X+=a
for i in r(m):a,*b=I();H+=(a,b),;X+=a,;Y+=b
def g(X):s=dict(enumerate(sorted(set(X))));return{s[i]:i for i in s},s,len(s)
h,s,K=g(X);w,t,L=g(Y);j=lambda:[[0]*-~K for i in r(L+1)];V=j();U=j();v=j()
for(a,b),c in R:U[w[c]][h[a]]+=1;U[w[c]][h[b]]-=1
for d,(e,f)in H:V[w[e]][h[d]]+=1;V[w[f]][h[d]]-=1
for i in r(L):
 for j in r(K):U[i][j+1]+=U[i][j];V[i+1][j]+=V[i][j]
q=[(h[0],w[0])];v[w[0]][h[0]]=1;a=0
while q:
 x,y=q.pop();a+=(s[x]-s[x+1])*(t[y]-t[y+1])
 for e,f in(-1,0),(1,0),(0,1),(0,-1),:
  c=x+e;d=y+f
  if 1-v[d][c]and U[(f>0)+y][x]|e==0|(V[y][(e>0)+x]|f==0):q+=[(c,d)];v[d][c]=1
print([a,'INF'][a>F])
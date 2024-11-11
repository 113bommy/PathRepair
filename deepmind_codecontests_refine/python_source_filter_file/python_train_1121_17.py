I=lambda:map(int,input().split());F=1e21;r=range;n,m=I();f=[-F,F];X=[0]+f;Y=X[:];R=[(f,F),(f,-F)];H=[(F,f),(-F,f)]
for i in r(n):a,b,c=I();R+=[((a,b),c)];Y+=[c];X+=[a,b]
for i in r(m):a,b,c=I();H+=[(a,(b,c))];X+=[a];Y+=[b,c]
s=dict(enumerate(sorted(set(X))));K=len(s);t=dict(enumerate(sorted(set(Y))));L=len(t);h=dict(zip(s.values(),s.keys()));w=dict(zip(t.values(),t.keys()));V=[[0]*-~K for i in r(L+1)];U=[i[:]for i in V];v=[i[:]for i in V]
for(a,b),c in R:U[w[c]][h[a]]+=1;U[w[c]][h[b]]+=-1
for i in r(L):
 for j in r(K):U[i][j+1]+=U[i][j]
for d,(e,f)in H:V[w[e]][h[d]]+=1;V[w[f]][h[d]]+=-1
for j in r(K):
 for i in r(L):V[i+1][j]+=V[i][j]
q=[(h[0],w[0])];v[w[0]][h[0]]=1;a=0
while q:
 x,y=q.pop();a+=(s[x]-s[x+1])*(t[y]-t[y+1])
 for e,f in[(-1,0),(1,0),(0,1),(0,-1)]:
  c=x+e;d=y+f
  if(K>c>=0<=d<L)*v[d][c]==0:
   if U[(f>0)+y][x]|e==0 or V[y][(e>0)+x]|f==0:q+=[(c,d)];v[d][c]=1
if a>F:a='INF'
print(a)
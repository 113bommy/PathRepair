N,K=map(int,input().split())
S=input()
X=[]
Y=[0]
_s='2'
for i,s in enumerate(S):
  if _s!=s:
    _s=s
    X.append(i)
    Y.append((int(s)+1)%2)
import itertools
Y=list(itertools.accumulate(Y))
ans=[]
for i,x in enumerate(X):
  if Y[-1]-Y[i]<=K:
    ans.append(N-x)
    break
  else:
    if S[x]=='0':
      ans.append(X[i+2*K]-x)
    else:
      ans.append(X[i+2*K+1]-x)
print(max(ans))
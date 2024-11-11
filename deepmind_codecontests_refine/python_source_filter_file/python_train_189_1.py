N,M=map(int,input().split())
section=[[] for i in range(M+1)]
for i in range(N):
  l,r=map(int,input().split())
  section[r-l+1].append((l,r))

def add(B,a,s):
    x=a
    while x<=len(B):
        B[x]+=s
        x+=x&(-x)
        
def sums(B,a):
    x=a
    S=0
    while x!=0:
        S+=B[x]
        x-=x&(-x)
    return S

Line=[0]*(M+2)
K=N
for d in range(1,M+1):
  for l,r in section[d]:
    add(Line,l,1)
    add(Line,r+1,-1)
    K-=1
  ans=K
  for s in range(M//d+1):
    ans+=sums(Line,s*d)
  print(ans)




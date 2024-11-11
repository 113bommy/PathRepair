import itertools
n=int(input())
A=[int(i) for i in input().split()]
B=[int(i) for i in input().split()]
def bitsum(BIT,i):
  s=0
  while i>0:
    s+=BIT[i]
    i-=i&(-i)
  return s

def bitadd(BIT,i,x):
  while i<=2**n:
    BIT[i]+=x
    i+=i&(-i)
  return BIT

def tentou(X):
  ret=0
  BIT=[0]*64
  BIT.insert(0,0)
  for i1 in range(n):
    x=X[i1]+1
    ret+=i1-bitsum(BIT,x)
    bitadd(BIT,x,1)
  return ret
N=[int(i) for i in range(n)]
nn=2**n
ans=float("inf")
for _ in range(n//2+1):
  for com in itertools.combinations(N,2*_):
    i=0
    for ura in com:
      i+=2**ura
    E,O=[],[]
    for j in range(n):
      if i&(1<<j)==0:
        if j%2==0:
          E.append(A[j]*100+j)
        else:
          O.append(A[j]*100+j)
      else:
        if j%2==0:
          O.append(B[j]*100+j)
        else:
          E.append(B[j]*100+j)
    if len(E)!=(n+1)//2:
      continue
    else:
      E.sort()
      O.sort()

      chk=True
      C=[E[0]%100]
      prev=E[0]//100
      for i in range(1,n):
        ii=i//2
        if i%2==0:
          C.append(E[ii]%100)
          if E[ii]//100<prev:
            chk=False
            break
          else:
            prev=E[ii]//100
        else:
          C.append(O[ii]%100)
          if O[ii]//100<prev:
            chk=False
            break
          else:
            prev=O[ii]//100
    
    if chk:
      ans=min(ans,tentou(C))
print(-1 if ans==float("inf") else ans)


import sys
input=lambda: sys.stdin.readline().rstrip()
n,q=map(int,input().split())
C=[int(i) for i in input().split()]
LR=[]
for i in range(q):
    l,r=map(int,input().split())
    LR.append((i,l,r))
LR.sort(key=lambda x:x[2])


LST=[0]*n
Ans=[0]*q

n_max=5*10**5+1
nn=n_max.bit_length()+1
BIT=[0]*(2**nn)
BIT.insert(0,0)

def bitsum(BIT,i):
  s=0
  while i>0:
    s+=BIT[i]
    i-=i&(-i)
  return s

def bitadd(BIT,i,x):
  while i<=2**nn:
    BIT[i]+=x
    i+=i&(-i)
  return BIT
cur=0
for i,l,r in LR:
    while cur<r:
        if LST[C[cur]]!=0:
            bitadd(BIT,LST[C[cur]],-1)
        LST[C[cur]]=cur+1
        bitadd(BIT,LST[C[cur]],1)
        cur+=1
    if l==1:
        Ans[i]=bitsum(BIT,r+1)
    else:
        Ans[i]=bitsum(BIT,r+1)-bitsum(BIT,l-1)
for ans in Ans:
    print(ans)
def main():
  def add(i,x):
    i+=1
    while i<=n:
      bit[i-1]+=x
      i+=i&-i
  def sum_sub(i):
    a=0
    i+=1
    while i:
      a+=bit[i-1]
      i-=i&-i
    return a
  def sum(i,j):
    a=sum_sub(j+1)
    if i!=0:a-=sum_sub(i-1)
    return a
  
  n,q,*x=map(int,open(0).read().split())
  a=x[:n]
  queries=[]
  for i in range(q):
    l,r=x[n+i*2:n+(i+1)*2]
    l-=1
    r-=1
    queries.append(r<<40|l<<20|i)
  ans=[0]*q
  queries.sort()
  for i in range(q):
    ind=queries[i]%(1<<20)
    queries[i]>>=20
    l=queries[i]%(1<<20)
    queries[i]>>=20
    r=queries[i]
    queries[i]=[r,l,ind]
  queries.append([10*20])
  lastAppeared=[-1]*n
  bit=[0]*n
  j=0
  for i in range(n):
    if lastAppeared[a[i]-1]!=-1:
      add(lastAppeared[a[i]-1],-1)
      add(i,1)
      lastAppeared[a[i]-1]=i
    else:
      add(i,1)
      lastAppeared[a[i]-1]=i
    while queries[j][0]==i:
      r,l,ind=queries[j]
      j+=1
      ans[ind]=sum(l,r-1)
  print(*ans)
if __name__ == "__main__":
  main()
import sys
def main():
  n,q,*c=map(int,sys.stdin.buffer.read().split())
  a=[0]*q
  j,*b=t=[0]*9**6
  for i in sorted(range(q),key=lambda x:c[x+x-~n]):
    l,r=c[i+i+n],c[i+i-~n]
    while j<r:
      k=c[j]
      j+=1
      x,y,b[k]=b[k]+1,j+1,j
      while x<=n:
        t[x]+=1
        x=x+(x&-x)
      while y<=n:
        t[y]-=1
        y=y+(y&-y)
    s=0
    while l:
      s=s+t[l]
      l=l-(l&-l)
    a[i]=s
  print(' '.join(map(str,a)))
main()
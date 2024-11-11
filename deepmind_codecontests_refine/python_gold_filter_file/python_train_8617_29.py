def main():
  import sys
  input=sys.stdin.buffer.readline
  n=int(input())+1
  data=[[0]*n*2for _ in range(26)]
  def update(i,x):
    i+=n
    for d in data:
      j=i
      if d[j]:
        d[j]=0
        j//=2
        while j:
          d[j]=d[j+j]|d[j-~j]
          j//=2
        break
    d=data[x]
    d[i]=1
    i//=2
    while i:
      d[i]=d[i+i]|d[i-~i]
      i//=2
  def query(l,r):
    l+=n
    r+=n
    s=[0]*26
    while l<r:
      if l&1:
        for i,d in enumerate(data):
          s[i]|=d[l]
        l+=1
      if r&1:
        r-=1
        for i,d in enumerate(data):
          s[i]|=d[r]
      l//=2
      r//=2
    return sum(s)
  for i,c in enumerate(input()[:-1],n):
    data[c-97][i]=1
  for d in data:
    for i in range(n-1,0,-1):
      d[i]=d[i+i]|d[i-~i]
  s=[]
  for _ in range(int(input())):
    q,a,b=input().split()
    if q[0]>49:
      s+=query(int(a)-1,int(b)),
    else:
      update(int(a)-1,b[0]-97)
  print(' '.join(map(str,s)))
main()
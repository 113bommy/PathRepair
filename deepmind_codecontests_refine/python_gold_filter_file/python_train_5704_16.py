def main():
  import sys
  b=sys.stdin.buffer
  h,w=map(int,b.readline().split())
  x=w+1
  s=[c>>3for c in b.read()]
  dp=[10000]*h*x
  a=p=s[0]
  dp[0]=b=q=5-a
  for i in range(w):
    t=s[i]
    b+=a^t
    dp[i]=b
    a=t
  for i in range(x,h*x,x):
    t=s[i]
    q+=p^t
    dp[i]=b=q
    a=p=t
    k=i-x
    for j in range(i+1,i+w):
      sj=s[j]
      b+=a^sj
      k+=1
      t=dp[k]+(s[k]^sj)
      if b>t:b=t
      dp[j]=b
      a=sj
  print(b+1>>1)
main()
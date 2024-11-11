n,x,m=map(int,input().split())
sm=[-1 for i in range(m)]
w=[-1 for i in range(m)]
d=[]
a=x
t=0
s=0
while True:
  s+=a
  if w[a]!=-1:
    inter=t-w[a]
    fv=w[a]
    ls=d[(n-fv)%inter+fv-1]
    lls=d[w[a]-1]
    print(sm[lls]+(n-fv)//inter*(s-sm[a])+(sm[ls]-sm[lls]))
    break
  w[a]=t
  d.append(a)
  sm[a]=s
  t+=1
  a=(a*a)%m
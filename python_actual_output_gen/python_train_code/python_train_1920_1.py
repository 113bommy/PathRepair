a1=int(input())
a2=int(input())
k1=int(input())
k2=int(input())
n=int(input())
h=a1*k1
x=a2*k2
total=a1*k1+a2*k2
g=n
t=0
if n>=total:
  print(a1+a2,a1+a2)
else:
  n-=h-x+a2+a1
  if k1<k2:
    if h<=g:
      t=a1+(g-h)//k2
    else:
      t=g//k1+(g%k1)//k2
    print(n if n>0 else 0,t)
  else:
    if x<=g:
      t=a2+(g-x)//k1
    else:
      t=g//k2+(g%k2)//k1

    print(n if n>0 else 0,t)
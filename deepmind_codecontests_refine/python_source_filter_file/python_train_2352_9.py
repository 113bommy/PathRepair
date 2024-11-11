def roi(b, k):
    d=101
    for i in range(len(b)):
        if b[i]<=k and b[i]!=0:
           d = b.index(b[i])+1
           break
    return d
n,m,k=map(int, input().split())
a = [int(i) for i in input().split()]
g = m-1
d=0
if g==0:
   q=roi(a[g+1:], k)
   print(10*q)
elif g==n-1:
   h=a[:g-1]
   h.reverse()
   q=roi(h, k)
   print(10*q)
else:
   if g!=0 and g!=n-1:
      j=a[:g]
      j.reverse()
      s=roi(j, k)
      p = roi(a[g+1:], k)
      if s<p:
         print(s*10)
      elif s>p:
         print(p*10)
      else:
         print(p*10)

def fact(n):
   if n==0:
      return 1
   else:
      return n*fact(n-1)
def comb(k,n):
   c=fact(n)
   d=fact(n-k)
   f=fact(k)
   f=f*d
   return int(c/f)
n,m,t=map(int,input().split())
t=t-5
if t==0:
   print(comb(4,n)*comb(1,m))
else:
   k=4+t
   s=0
   h=1
   if k>n:
      h+=k-n
      k=n
   while m>=h and k>=n:
      s+=(comb(k,n)*comb(h,m))
      h+=1
      k-=1
   print(s)
   

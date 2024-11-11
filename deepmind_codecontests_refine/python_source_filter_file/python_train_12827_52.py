def recursion(n):
   sums=0
   for i in range(n,1,-1):
      sums=sums+(1/n)
   return sums   
try:
   n=int(input())
   ans=recursion(n)
   print(format(ans,'.12f'))
except Exception as e:
   print(e)
t=int(input())
for i in range(t):
   n,m,k=map(int,input().split(' '))
   if m==0:
      print("0")
   elif (n//k)>=m:
      print(m)
   else:
      a=n//k
      s=0
      for i in range(a):
         if (a-1)*(k-1)>(m-a):
            s+=i
            break
      print(s)
      
      
   
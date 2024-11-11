t=int(input())
for i in range(t):
   n=int(input())
   if n==1:
      print("0")
   else:
      k=(n-1)//2
      s=(4*(k)*(k+1)*(2*k+1))//3
      print(s)
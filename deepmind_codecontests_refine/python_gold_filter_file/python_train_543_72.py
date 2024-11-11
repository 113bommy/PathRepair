n=int(input())
for i in range(n):
   a=int(input())
   a=(a-1)//2
   print(((a*(a+1)*(2*a+1))//6)*8)
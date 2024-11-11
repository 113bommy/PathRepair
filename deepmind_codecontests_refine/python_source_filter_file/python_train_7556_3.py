def calc(n):
   g = n 
   m = 1 
   while n > 10 :
       m = m * 10 
       n = int(n / 10) 
   m = m * (1 + n)
   return m - g     

n = int(input())
print(calc(n))




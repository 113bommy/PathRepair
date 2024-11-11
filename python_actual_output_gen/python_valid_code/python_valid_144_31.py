n,m = map(int, input() .split())
x= list(map(int, input() .split()))
a=1
if n == 1:
  print(1)
  exit()
else:  
  for i in range(n):
   if (x[i+1] - x[i]) <= m :
      a+=1
   else:
      a = 0
   i+=1    
   if i + 1 >= n:
      break

print(a+1) 

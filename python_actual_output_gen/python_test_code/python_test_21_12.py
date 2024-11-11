n = int(input())
t = ((n*n) / 2) + 0.5
print(int(t))
if n % 2 == 0:
  for i in range(n):
    if i % 2 != 0:
      print('C.'*(n//2))
    else:
      print('.C'*(n//2))
else:
  for j in range(n):
    if j % 2 !=0 :  
      print('C.'*(n//2),end = '')
      print('C')
    else:
      print('.C'*(n//2),end ='') 
      print('.')     

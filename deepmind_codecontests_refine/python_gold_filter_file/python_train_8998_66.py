n = int(input())

if n%2 : print(0)
else : 
  Hash = {1:2,2:4,3:3,4:1}
  print((Hash[(n+1)%4]+2)%5)
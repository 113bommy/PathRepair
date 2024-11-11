t = int(input())
n = []

for i in range(t):  
  n.append(int(input()))

for i in n:  
  sum1 = (1 + i) * i // 2 
  j=0
  g=0   
  while j<=i:
    if j == 2**g :
      sum1 = sum1 - 2*j
      g = g + 1
    j = 2**g

  print(sum1)
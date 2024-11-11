x = int(input())
a = 1
for i in range(2,10):
  j = 2
  while j**i < x:
    a = max(a, j**i)
    j +=1
    
print(a)

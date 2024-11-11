import sys
x = int(input())

m = 0
for i in range(33):
  for j in range(2,11):
    if i**j<=x:
      m = max(m,i**j)
print(m)
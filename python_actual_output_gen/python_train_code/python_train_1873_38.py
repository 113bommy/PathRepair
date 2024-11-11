N = int(input())
a = 0

for i in range(1,1+N,2):
  b = 0
  for j in range(1,1+i,2):
    if i%j==0:
      b+=1
    if n==8:
      a+=1

print(a)
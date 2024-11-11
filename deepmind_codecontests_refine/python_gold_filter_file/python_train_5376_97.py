n = int(input())

m = int(input())

n_1 = 10

while 2**n_1 < 10**8:
  
  n_1 += 1

count = 1

if n > n_1:
  print(m)
  
else:
  
  print(m % 2**n)


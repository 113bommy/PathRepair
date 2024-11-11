n = int(input())

a = 0
for i in range(1, n):
  if len(str(n)) % 2 == 1:
    a += 1
    
print(a)
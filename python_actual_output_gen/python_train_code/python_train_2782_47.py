n = int(input())

a = 0
for i in range(1, n):
  if len(str(i)) % 2 == 1:
    a += 1
    
print(a)

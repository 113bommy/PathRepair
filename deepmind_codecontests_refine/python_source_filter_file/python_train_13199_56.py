n = int(input())

for i in range(1, n**.5+1):
  if n%i == 0:
    p = i

q = n//p

print(p+q-2)
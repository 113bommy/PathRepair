n = int(input())

a = []

for i in range(n):
  a.append(int(input())

print('second' if all(a[i] % 2 == 0 for i in range(n)) else 'first')

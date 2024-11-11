N = int(input())
a = []
for i in range(N):
  a.append(int(input()))
print('second' if all(a[i] % 2 == 0 for i in range(N)) else 'first')

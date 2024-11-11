n =int(input())
A = set()
for i in range(n):
  A ^= {int(input())}
print(len(A))
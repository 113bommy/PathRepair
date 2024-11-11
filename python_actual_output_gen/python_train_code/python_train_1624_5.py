n = int(input())
A = []
B = []
for i in range(n):
  a, b = map(int,input().split())
  A.append(a)
  B.append(b)
print(max(a)+min(b))
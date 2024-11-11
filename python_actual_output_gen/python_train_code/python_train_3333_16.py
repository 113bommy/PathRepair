n = int(input())
a = list(map(int, input().split()))
b = 0
for i in range(1,n,2):
  if a[i] %2 == 1:
    b += 1
print(b)
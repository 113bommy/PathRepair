n = int(input())
a = list(map(int, input().split()))

m = 0
im = 0
for i, ai in enumerate(a):
  if abs(ai) >= abs(m):
    m = ai
    im = i
print(2*n)

for i in range(n):
  print(im+1, i+1)

if im > 0:
  for i in range(0, n-1):
    print(i+1, i+2)
else:
  for i in reversed(range(1, n)):
    print(i+1, i)
    

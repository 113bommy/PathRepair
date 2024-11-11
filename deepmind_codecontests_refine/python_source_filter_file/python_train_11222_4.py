N = int(input())
H = list(map(int, input().split()))
 
a, b = 0, 0
for i in range(N-1):
  if H[i] >= H[i+1]: b += 1
  else: 
    b = 0
    a = max(a, b)
print(a)
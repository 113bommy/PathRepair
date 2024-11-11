n, m, k = map(int, input().split())
for i in range(n+1):
  for j in range(m+1):
    if m*i + n*j - i*j*2 == k:
      print("Yes")
      exit()
print("No")

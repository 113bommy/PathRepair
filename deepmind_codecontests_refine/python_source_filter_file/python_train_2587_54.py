K, S = map(int, input().split())
m=0
for i in range(K):
  for j in range(K):
    if 0<=S-i-j<=K:
      m+=1
print(m)
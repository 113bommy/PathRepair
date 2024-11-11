n = int(input()) 
arr= list(map(int,input().split()))
rel = list(range(n))
prev = -n
for i in range(n):
  if arr[i] == 0:
    prev = i
  rel[i] = i - prev
prev = n + n
for i in range(n - 1,-1,-1):
  if rel[i] == 0:
    prev = i
  rel[i] = min(rel[i],prev - i )
print(*rel)
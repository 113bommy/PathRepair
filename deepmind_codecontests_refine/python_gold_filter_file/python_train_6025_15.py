N, L = map(int, input().split())
As = list(map(int, input().split()))

i = 0

for j in range(1,N):
  if As[j-1] + As[j] >= L:
    i = j
    break
    
if i == 0:
  print('Impossible')
else:
  print('Possible')
  for j in range(1,i):
    print(j)
  for j in range(N-1,i,-1):
    print(j)
  print(i)
n = int(input())
L = input()
if L[0:n//2] == L[n//2:n]:
  print('Yes')
else:
  print('No')
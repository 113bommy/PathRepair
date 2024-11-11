from collections import Counter
def check():
  H, W = map(int, input().split())
  A = []
  for i in range(H):
    A.extend(list(input()))
  c = Counter(A)
  one = 0
  two = 0
  for v in c.values():
    if v%2==1:
      one += 1
    if v%4==2:
      two += 1
  if H%2==0 and W%2==0:
    if one+two>0:
      return 'No'
  if H%2==0 and W%2==1:
    if two>H//2 or one>0:
      return 'No'
  if H%2==1 and W%2==0:
    if two>W//2 or one>0:
      return 'No'
  if H%2==0 and W%2==0:
    if two>W//2+H//2 or one>1:
      return 'No'
  return 'Yes'
print(check())
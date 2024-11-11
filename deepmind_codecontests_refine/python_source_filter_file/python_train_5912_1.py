n,k,c = map(int,input().split())
S = input()

left = [ -1 for i in range(k)]
right = [ -1 for i in range(k)]

pointer = 0
for l in range(k):

  for s in range(pointer,n):
    if S[s] == 'o':
      left[l] = s
      pointer = s+c
      break

pointer = n-1
for r in range(k):

  for s in range(pointer,0,-1):
    if S[s] == 'o':
      right[r] = s
      pointer = s-c
      break

for l,r in zip(left, right[::-1]):
  if l==r:
    print(l+1)

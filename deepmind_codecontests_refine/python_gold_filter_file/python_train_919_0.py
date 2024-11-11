n, k = map(int,input().split())
A = list(map(int,input().split()))

pos = 0
neg = 0

for a in A[:k]:
  if a>0:
    pos += a
  else:
    neg += a
  
wp = pos
wn = neg
ans = float('inf')
for i,a in enumerate(A[k:]):
  if a>0:
    pos += a
    wp += a
  else:
    neg += a
    wn += a
  b = A[i]
  if b>0:
    wp -= b
  else:
    wn -= b
  ans = min(ans, wp, -wn)
print(max(pos - ans, pos+neg, 0))
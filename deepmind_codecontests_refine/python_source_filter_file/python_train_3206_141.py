a, b, k = map(int, input().split())
if k < a:
  a=a-k
else:
  b=b-(k-a)
  a=0
print(a,b)
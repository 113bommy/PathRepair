n = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

k = sum(B)-sum(A)
cb = sum([a-b for b,a in zip(B,A) if b<a])
ca = sum([(b-a+1)//2 for b,a in zip(B,A) if b>a])
if ca+cb <= k:
  print('Yes')
else:
  print('No')
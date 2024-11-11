a,b,c=map(int,input().split())
k=int(input())
for n in range(k):
  if a>b:
    b=b*2
  elif b>c:
    c=c*2
if b>a and c>b:
  print('Yes')
else:
  print('No')
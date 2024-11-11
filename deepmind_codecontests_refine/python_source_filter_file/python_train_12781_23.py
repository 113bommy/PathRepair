a,b,c=map(int,input().split())
k=int(input())
while a>b:
  k-=1
  b*=2
if k>=0:
  print('Yes' if c*(2**k)>b else 'No')
else:
  print('No')
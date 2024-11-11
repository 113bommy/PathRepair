n=int(input())
a=list(map(int,input().split()))
s=0
for i in a:
  if i%2==0:
    if i%3!=0 and i%5!=0:
      s=s+1
print('DENIED' if s>0 else 'APPROVED')
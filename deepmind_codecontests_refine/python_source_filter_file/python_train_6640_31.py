n=int(input())
a=list(map(int,input().split()))
s=0
for i in a:
  if a%2==0:
    if a%3!=0 and a%5!=0:
      s=s+1
print('DENIED' if s>0 else 'APPROVED')
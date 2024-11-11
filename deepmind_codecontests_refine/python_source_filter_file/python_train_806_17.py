n=int(input())
l=list(map(int,input().split()))
mx=l[0]
an=0
for i in range(1,n):
  if l[i]<mx:
    an+=mx-l[i]
  else:
    l[i]=mx
print(an)
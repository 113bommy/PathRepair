from random import sample
n=int(input())
if n==3:a=[2,3,63]
else:
  l=[i for i in range(6,30001)if i%2==0 or i%3==0]
  while True:
    a=[2,3,4];a+=sample(l,n-3)
    if sum(a)%6==0:break
print(*a)
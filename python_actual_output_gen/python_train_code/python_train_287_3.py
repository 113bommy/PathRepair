n=int(input())
a=list(map(int,input().split()))
sm=0
b=a[0]
for i in range(1,n): 
  if a[i]<a[i-1]:
    sm+=b-a[i]
  else:
    b=a[i]
print(sm)

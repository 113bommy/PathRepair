n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

cnt=0
margin=0
for i in range(n):
  x=a[i]
  y=b[i]
  if x>y:
    cnt+=x-y
  elif x<y:
    margin+=(y-x)//2

print('Yes' if margin>=cnt else 'No')
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

cnt=0
for i in range(n):
  x=a[i]
  y=b[i]
  if x>y:
    cnt+=x-y
  elif x<y:
    cnt-=(y-x)//2

print('Yes' if cnt>=0 else 'No')
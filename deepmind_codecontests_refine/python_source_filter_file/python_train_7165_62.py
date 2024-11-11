n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
x=0;y=0
for i in range(n):
  if a[i]<b[i]:
    x+=(b[i]-a[i])
  else:
    y+=(a[i]-b[i])
print('Yes' if x//2>=y else 'No')
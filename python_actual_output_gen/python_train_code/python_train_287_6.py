n=int(input())
a=list(map(int,input().split()))
b=a

s=0
for i in range(n-1):
  if b[i]>a[i+1]:
    s+=(a[i]-a[i+1])
    b[i+1]=b[i]
print(s,a,b)
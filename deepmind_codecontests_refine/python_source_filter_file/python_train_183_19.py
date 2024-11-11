n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
x=0
for i in range(0,n-1):
  if a[i]=a[i+1]:
    x+=c[a[i]-1]
y=sum(b)
print(x+y)
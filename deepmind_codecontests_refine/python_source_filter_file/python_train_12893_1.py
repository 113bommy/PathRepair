n=int(input())
a=list(map(int,input().split()))
b=[0]*n
b[0]=a[0]
for i in range(1,n):
  b[i]=b[i-1]+a[i]
p=1
for i in range(n-1)[::-1]:
  if b[i]*2>=a[i+1]:
    p+=1
  else:
    break
print(p)
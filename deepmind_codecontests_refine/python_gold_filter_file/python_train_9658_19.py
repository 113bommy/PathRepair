N=int(input())

a=list(map(int,input().split()))
x=0
for i in range(N):
  if i%2==0 and a[i]%2==1:
    x+=1
print(x)
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
p=O
for i in range(n):
  p+=b[a[i]-1]
  if i>=1 and a[i]-a[i-1]==1:
    p+=c[a[i-1]-1]
print(p)
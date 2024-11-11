n=int(input())
a=list(map(int,input().split()))
s=0
for _ i range(n):
  b=a[_]
  while b%2==0:
    b=b/2
    s+=1
print(s)
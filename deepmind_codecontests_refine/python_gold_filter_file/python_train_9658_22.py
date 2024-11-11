N=int(input())
a=list(map(int,input().split()))
c=0
for x in range(N):
  if x%2==0 and a[x]%2==1:
    c += 1
print(c)
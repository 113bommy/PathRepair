n=int(input())
ans=2**n
m=1
for a in map(int,input().split()):
  if a%2==0:
    m*=2
print(ans-m)
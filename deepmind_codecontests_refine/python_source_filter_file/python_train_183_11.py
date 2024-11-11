n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))

ans=0

for x,y in zip(a,a[1:]):
  if y == x+1:
    ans += c[x-1]
    
print(sum(y)+ans)
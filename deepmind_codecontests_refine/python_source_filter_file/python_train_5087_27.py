n=int(input())
a=list(map(int,input().split()))
ans=0
for i in range(n):
  j = a[i]
  if a[j] == i:
    ans+=1
print(ans//2)
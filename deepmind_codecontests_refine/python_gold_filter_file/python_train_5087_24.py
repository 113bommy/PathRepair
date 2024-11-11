n = int(input())
a = tuple(map(lambda a:int(a)-1,input().split()))

ans = 0
for i in range(n):
  if a[a[i]]==i:
    ans+=1
print(ans//2)

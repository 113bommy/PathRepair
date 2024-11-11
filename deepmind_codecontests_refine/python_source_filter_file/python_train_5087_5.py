n =int(input())
lis =list(map(int,input().split()))
ans =0
for i in range(n):
  if lis[lis[i]-1]=i+1:
    ans +=1
print(ans//2)
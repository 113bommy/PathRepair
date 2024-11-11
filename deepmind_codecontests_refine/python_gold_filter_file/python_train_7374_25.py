n=int(input())
sum=0
for i in range(n):
  l, r =map(int, input().split())
  sum+=(r-l+1)
print(sum)
n=int(input())
p = list(map(int, input().split()))
sum = 0
for i in range(1,n):
  if p[i+1]>p[i]>p[i-1] or p[i-1]>p[i]>p[i+1]:
    sum +=1
print(sum)

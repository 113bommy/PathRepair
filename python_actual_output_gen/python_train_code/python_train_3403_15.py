n,a,b = map(int, input().split())

count=0
for i in range(1,n+1):
  if sum(int(j) for j in str(i))<=b:
    count+=i

print(count)
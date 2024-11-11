n = int(input())
arr = list(map(int,input().split()))
cur=1000
for i in range(n-1):
  p=0
  if arr[i] < arr[i+1]:
    p=cur // arr[i]
  cur += (arr[i+1] - arr[i])*p
print(cur)

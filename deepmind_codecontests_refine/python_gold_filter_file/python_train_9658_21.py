n = int(input())
arr = list(map(int, input().split()))
ans = 0
for i in range(0, n, 2):
  if arr[i]%2:ans+=1
print(ans)

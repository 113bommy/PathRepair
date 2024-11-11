N = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(N):
  if a[a[i]-1] == i+1:
    ans += 1
print(ans//2)
n = int(input())
a = list(map(int, input().split()))
r = 0
cnt = 0
for i in range(n-1):
 if 2*a[i] >= a[i+1]:
  cnt += 1
 else:
  r = max(r,cnt)
  cnt = 0
print(r+1)
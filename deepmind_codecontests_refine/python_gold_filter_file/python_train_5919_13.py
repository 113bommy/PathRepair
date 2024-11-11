n = int(input())
a = list(map(int, input().split()))

ans = 0
diff = 0
for i in range(1, n):
  tmp_diff = a[i] - a[i - 1]
  if tmp_diff != 0 and diff == 0:
    diff = tmp_diff
    continue
  if not(tmp_diff == 0 or tmp_diff * diff > 0):
    ans += 1
    diff = 0
    continue
print(ans + 1)
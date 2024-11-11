n, k = map(int, input().split())
s = list(input())
k -= 1
def goright():
  for i in range(n):
    print("PRINT " + s[i])
    if i < n - 1:
      print("RIGHT")
def goleft():
  for i in range(n):
    print("PRINT " + s[n - i - 1])
    if i < n - 1:
      print("LEFT")
if k == 0:
  goright()
elif k == n - 1:
  goleft()
elif n - k > (n / 2):
  for i in range(k + 1):
    print("LEFT")
  goright()
else:
  for i in range(n - k - 1):
    print("RIGHT")
  goleft()

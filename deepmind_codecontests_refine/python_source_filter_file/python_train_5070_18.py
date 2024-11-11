n,b = map(int, input().split())
arr = list(map(int, input().split()))
money = list()
c0 = 0
c1 = 0
for i in range(n):
  if arr[i]%2 == 0:
    c0 += 1
  else:
    c1 += 1
  if c0 == c1 != 0:
    money.append(abs(arr[i]-arr[i-1]))
    c0, c1 = 0, 0
money.sort()
count = 0
for i in money:
  if b - i >= 0:
    count += 1
    b -= i
  else:
    break
print(count)

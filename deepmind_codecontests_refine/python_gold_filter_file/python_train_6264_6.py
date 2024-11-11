n = int(input())
array = list(map(int, input().split()))



i1 = 0
while (i1 < n - 1) and (array[i1] < array[i1 + 1]):
  i1 += 1
if (i1 == n - 1):
  print("YES")
else:
  while (i1 < n - 1) and (array[i1] > array[i1 + 1]):
    i1 += 1
  if (i1 == n - 1):
    print("YES")
  else:
    print("NO")  
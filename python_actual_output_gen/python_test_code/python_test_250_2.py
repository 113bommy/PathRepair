n = int(input())
h = list(map(int, input().split()))

judge = 0
for i in range(n):
  if a[i] < judge:
    print("No")
    break
  judge = max(judge, a[i]-1)
else:
  print("Yes")
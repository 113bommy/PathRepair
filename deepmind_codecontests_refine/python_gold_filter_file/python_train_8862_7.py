n = int(input())
a = list(map(int, input().split()))

sortA = sorted(a)
i, j = 0, 0
maxi = 0
while i < n and j < n:
  if sortA[j] - sortA[i] <= 5:
    if j - i + 1 > maxi:
      maxi = j - i + 1
    j += 1
  else:
    i += 1
print(maxi)

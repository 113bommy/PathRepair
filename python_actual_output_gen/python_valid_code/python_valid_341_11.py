n = int(input())
a = sorted(list(map(int,input().split())))[::-1]

for i in range(n-3):
  if a[i] == a[i+1]:
    for j in range(i+2, n):
      if a[j] == a[j] + 1:
        print(a[i] * a[j])
        exit()

print(0)
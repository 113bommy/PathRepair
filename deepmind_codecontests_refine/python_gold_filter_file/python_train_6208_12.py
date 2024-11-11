a = list(map(int, input().split()))
a.sort()
for i in range(len(a)):
  for j in range(i+1, len(a)):
    for k in range(j+1, len(a)):
      if a[i] + a[j] + a[k] == (sum(a)) / 2:
        print('YES')
        exit()
print("NO")
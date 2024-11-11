n, k = map(int, input().split(' '))
a = sorted(list(map(int, input().split(' '))))
a.reverse()
print(a)
if k > n:
  print(-1)
else:
  print(str(a[k - 1]) + ' 0')
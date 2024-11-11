for _ in range(int(input())):
  n, x = map(int, input().split())
  if n <= 2:
    print(1)
  else:
    res, remain = divmod(n - 3, x)
    print(res + 2)
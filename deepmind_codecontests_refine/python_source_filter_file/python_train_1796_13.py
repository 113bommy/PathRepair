for _ in range(int(input())):
  n, k = map(int, input().split())

  if n&1 and k&1^1:
    print("NO")
  elif n&1^1 and k&1:
    if n < 2*k:
      print("NO")
    else:
      print("YES")
      for i in range(k - 1):
        print(2, end=" ")
      print(n - k - 1)
  else:
    if n < k:
      print("NO")
    else:
      print("YES")
      for i in range(k - 1):
        print(1, end=" ")
      print(n - k + 1)

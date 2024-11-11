n = int(input())
x = list(input())
st = x.count("X")
if st == n / 2:
  print(0)
  print("".join(x))
elif st > n / 2:
  count = st - n / 2
  while count > 0:
    index = x.index("X")
    x[index] = "x"
    count -= 1
    print(int(abs(st - n / 2)))
    print("".join(x))
else:
  count = abs(st - n / 2)
  while count > 0:
    index = x.index("x")
    x[index] = "X"
    count -=1
    print(int(abs(st - n / 2)))
    print("".join(x))

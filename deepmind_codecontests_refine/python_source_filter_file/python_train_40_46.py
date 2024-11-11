def cf_379a():
  a, b = map(int, input().split())
  sum_ = 0
  while a >= b:
    sum_ += a
    a = a - ((a // b) * b) + a // b
  print(int(sum_))

if __name__ == '__main__':
  cf_379a()
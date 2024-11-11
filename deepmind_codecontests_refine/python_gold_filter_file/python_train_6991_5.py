def func(x, y):
  if x > y:
    print('+')
  elif x < y:
    print('-')
  else:
    print('0')

if __name__ == '__main__':
  x, y, z = tuple([int(x) for x in input().split(' ')])
  if z == 0:
    func(x, y)
  elif z >= abs(x - y):
    print("?")
  else:
    func(x, y)
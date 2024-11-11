for n in range(1,10):
  for i in range(1, 10):
    print('{} x {} = {}\n'.format(n, i, eval('{}*{}'.format(n, i))))
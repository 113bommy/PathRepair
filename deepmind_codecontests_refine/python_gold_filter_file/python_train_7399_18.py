while True:
  try:
    print(int(eval(input())))
  except SyntaxError:
    break
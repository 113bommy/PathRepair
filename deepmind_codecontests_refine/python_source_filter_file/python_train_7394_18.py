while True:
  try:
    print(eval(input()))
  except SyntaxError:
    break
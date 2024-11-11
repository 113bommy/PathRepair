while 1:
  a,o,b = input().split()
  if o=='?': break
  a,b = int(a,b)
  print(a+b if o=='+' else a-b if o=='-' else a*b if o=='*' else a//b)

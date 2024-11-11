while True:
 a, op, b = input().split()
 a = int(a)
 b = int(b)

 if op == '?':
  break

 if op == '+':
  ans = a+b
 elif op == '-':
  ans = a-b
 elif op == '*':
  ans = a*b
 else:
  ans = a/b

 print('%d' %(ans))

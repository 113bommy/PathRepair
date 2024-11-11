n=int(input())
if [i for i in [int(input()) for _ in range(n)] if i % 2]:
  print('first')
 else:
  print('second')
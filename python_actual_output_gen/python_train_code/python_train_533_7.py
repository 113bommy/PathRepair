n = int(input())
min_y = -2000000000
max_y = 2000000000
Impossible = False

def opposite(sign):
  if sign == '>':
    return '<='
  if sign == '<':
    return '>='
  if sign == '<=':
    return '>'
  if sign == '<=':
    return '<'

for i in range(n):
  sign, number, ans = input().split(' ')
  if ans == 'N':
    sign = opposite(sign)
  if sign == '>':
    min_y = max(min_y, int(number) + 1)
  if sign == '<':
    max_y = min(max_y, int(number) - 1)
  if sign == '>=':
    min_y = max(min_y, int(number))
  if sign == '<=':
    max_y = min(max_y, int(number))
  if max_y < min_y:
    Impossible = True
    break

if Impossible == True:
  print('Impossible')
else:
  print(min_y)
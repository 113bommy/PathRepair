white = 0
black = 0
for i in range(8):
  s = input().strip()
  for j in s:
    if j == 'Q':
      white += 8
    elif j == 'R':
      white += 5
    elif j == 'B' or j == 'N':
      white += 3
    elif j == 'P':
      white += 1
    elif j == 'q':
      black += 8
    elif j == 'r':
      black += 5
    elif j == 'b' or j == 'n':
      black += 3
    elif j == 'p':
      black += 1
if white > black:
  print('White')
elif black > white:
  print('Black')
else:
  print('Draw')

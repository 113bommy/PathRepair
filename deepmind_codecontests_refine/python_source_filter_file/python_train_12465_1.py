line1 = input()
line2 = input()
boards = [['' for x in range(len(line1))] for y in range(2)]
for i in range(len(line1)):
  boards[0][i] = line1[i]
  boards[1][i] = line2[i]
count = 0
for x in range(len(line1)-1):
  if 3 <= boards[0][x:x+2].count('0') + boards[1][x:x+2].count('0'):
    count += 1
    if boards[0][x] =='0':
      if boards[0][x+1] == '0':
        boards[0][x] = 'X'
        boards[1][x] = 'X'
        if boards[1][x] =='0':
          boards[1][x+1] = 'X'
        else:
          boards[1][x] = 'X'
      else:
        boards[0][x] = 'X'
        boards[1][x] = 'X'
        boards[1][x+1] = 'X'
    else:
      boards[0][x+1] = 'X'
      boards[1][x] = 'X'
      boards[1][x+1] = 'X'
print(count)
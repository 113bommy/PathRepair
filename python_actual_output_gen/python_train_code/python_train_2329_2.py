num = int(input())
root = num**0.5
if (root == int(root)):
  print(int(root),int(root))
else:
  row = 1
  col = num
  factor = 2
  newcol = num
  newrow = 1
  finalrow = 1
  finalcol = num
  while newrow <= newcol:
    factor += 1
    if (newcol == int(newcol)) and ((newcol-newrow)<(col-row)):
      finalrow = newrow
      finalcol = newcol
    newcol = col/factor
    newrow = row*factor
  print(int(finalrow),int(finalcol))
def sudoku():
  x11, x21, x31 = [int(x) for x in input().split()]
  x12, x22, x32 = [int(x) for x in input().split()]
  x13, x23, x33 = [int(x) for x in input().split()]
  
  for i in range(0, 100001):
    x11 = i
    x22 = (x11 + x21 + x31) - (x12 + x32)
    x33 = (x11 + x21 + x31) - (x22 + x11)
    if ((x11 + x22 + x33) == (x11 + x21 + x31) == (x31 + x32 + x33)) :
      print(x11,x21,x31)
      print(x12,x22,x32)
      print(x13,x23,x33)
      return
sudoku()


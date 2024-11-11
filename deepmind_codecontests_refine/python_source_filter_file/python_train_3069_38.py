board=[]
for i in range(8):
  k=input()
  board.append(k)
white=0
black = 0
for i in range(8):
  for j in range(8):
    if board[i][j]=="K":
      white+=0
    if board[i][j]=="Q":
      white+=9
    if board[i][j]=="R":
      white+=5
    if board[i][j]=="B":
      white+=3
    if board[i][j]=="N":
      white+=3
    if board[i][j]=="P":
      white+=1
    if board[i][j]==".":
      pass
    if board[i][j]=="k":
      black+=0
    if board[i][j]=="q":
      black+=9
    if board[i][j]=="r":
      black+=5
    if board[i][j]=="b":
      black+=3
    if board[i][j]=="n":
      black+=3
    if board[i][j]=="p":
      black+=1
if black > white:
  print("black")
elif white>black:
  print("white")
else:
  print("draw")






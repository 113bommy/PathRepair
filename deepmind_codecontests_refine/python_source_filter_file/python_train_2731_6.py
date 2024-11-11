
for t in range(int(input())):
  row=[[],[],[],[],[],[],[],[],[]]
  for i in range(9):
    l=input()
    for j in range(9):
        row[i].append(l[j])
  #print(row)
  row[0][0]=row[0][1]
  row[1][3]=row[1][4]
  row[2][6]=row[2][7]
  row[3][1]=row[3][2]
  row[4][4]=row[4][5]
  row[5][7]=row[5][8]
  row[6][2]=row[6][3]
  row[7][5]=row[7][6]
  row[8][8]=row[8][7]
  
  
  for i in range(9):
    string=""
    for j in range(9):
      string+=row[0][j]
    print(string)
  
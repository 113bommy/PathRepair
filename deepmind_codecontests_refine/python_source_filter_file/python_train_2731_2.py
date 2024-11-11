t=int(input())
for i in range(t):
    num1=[]
    for i in range(9):
        num2=str(input())
        num3=[]
        for j in num2:
            num3.append(int(j))
        num1.append(num3)
    if num1[0][0]==9:
        num1[0][0]==1
    if num1[0][0]!=9:
        num1[0][0]+=1
    if num1[1][3]==9:
        num1[1][3]==1
    if num1[1][3]!=9:
        num1[1][3]+=1
    if num1[2][6]==9:
        num1[2][6]==1
    if num1[2][6]!=9:
        num1[2][6]+=1
    if num1[3][1]==9:
        num1[3][1]==1
    if num1[3][1]!=9:
        num1[3][1]+=1
    if num1[4][4]==9:
        num1[4][4]==1
    if num1[4][4]!=9:
        num1[4][4]+=1
    if num1[5][7]==9:
        num1[5][7]==1
    if num1[5][7]!=9:
        num1[5][7]+=1
    if num1[6][2]==9:
        num1[6][2]==1
    if num1[6][2]!=9:
        num1[6][2]+=1
    if num1[7][5]==9:
        num1[7][5]==1
    if num1[7][5]!=9:
        num1[7][5]+=1
    if num1[8][8]==9:
        num1[8][8]==1
    if num1[8][8]!=9:
        num1[8][8]+=1
    for i in num1:
        a=""
        for j in i:
            a+=str(j)
        print(a)
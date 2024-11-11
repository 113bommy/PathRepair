m = []
for x in range(10):
    m.append(input())
t = False
for y in range(10):
    for x in range(10):
        if x<6:
            if m[y][x+1] == m[y][x+2] == m[y][x+3] == m[y][x+4]=="X" and m[y][x]!="O":
                t = True
                break
        if x>0 and x<7:
            if m[y][x-1] == m[y][x+1] == m[y][x+2] == m[y][x+3]=="X" and m[y][x]!="O":
                t = True                            
                break
        if x>1 and x<8:
            if m[y][x-1] == m[y][x-2] == m[y][x+1] == m[y][x+2]=="X" and m[y][x]!="O":
                t = True
                break
        if x>2 and x<9:
            if m[y][x-1] == m[y][x-2] == m[y][x-3] == m[y][x+1]=="X" and m[y][x]!="O":

                t = True
                break
        if x>3:
            if m[y][x-1] == m[y][x-2] == m[y][x-3] == m[y][x-4]=="X" and m[y][x]!="O":

                t = True
                break
        if x<6 and y <6:
            if  m[y][x]!="O" and m[y+1][x+1] == m[y+2][x+2] == m[y+3][x+3] == m[y+4][x+4]=="X":
                t = True
                break
        if x<7 and y <7 and  x>0 and y >0 :
            if  m[y][x]!="O" and m[y-1][x-1] == m[y+1][x+1] == m[y+2][x+2] == m[y+3][x+3]=="X":
                t = True
                break
        if x<8 and y <8 and  x>1 and y >1:
            if  m[y][x]!="O" and m[y-1][x-1] == m[y-2][x-2] == m[y+1][x+1] == m[y+2][x+2]=="X":
                t = True
                break
        if x<9 and y <9 and  x>2 and y >2:
            if  m[y][x]!="O" and m[y-1][x-1] == m[y-2][x-2] == m[y-3][x-3] == m[y+1][x+1]=="X":
                t = True
                break
        if x>3 and y >3:
            if  m[y][x]!="O" and m[y-1][x-1] == m[y-2][x-2] == m[y-3][x-3] == m[y-4][x-4]=="X":
                t = True
                break
        if x > 3 and y < 6:
            if  m[y][x]!="O" and m[y+1][x-1] == m[y+2][x-2] == m[y+3][x-3] == m[y+4][x-4]=="X":
                t = True
                break
        if x>2 and y <7 and  x<9 and y >0:
            if  m[y][x]!="O" and m[y-1][x+1] == m[y+1][x-1] == m[y+2][x-2] == m[y+3][x-3]=="X":
                t = True
                break
        if x>1 and y <8 and  x<8 and y >1:
            if  m[y][x]!="O" and m[y+1][x-1] == m[y+2][x-2] == m[y-1][x+1] == m[y-2][x+2]=="X":
                t = True
                break
        if x>0 and y <9 and  x<7 and y >2:
            if  m[y][x]!="O" and m[y+1][x-1] == m[y-1][x+1] == m[y-2][x+2] == m[y-3][x+3]=="X":
                t = True
                break
        if x<6 and y >3:
            if  m[y][x]!="O" and m[y-1][x+1] == m[y-2][x+2] == m[y-3][x+3] == m[y-4][x+4]=="X":
                t = True
                break
        if y<6:
            if m[y+1][x] == m[y+2][x] == m[y+3][x] == m[y+4][x]=="X" and m[y][x]!="O":

                t = True
                break
        if y>0 and y<7:
            if m[y-1][x] == m[y+1][x] == m[y+2][x] == m[y+3][x]=="X" and m[y][x]!="O":

                t = True
                break
        if y>1 and y<8:
            if m[y-1][x] == m[y-2][x] == m[y+1][x] == m[y+2][x]=="X" and m[y][x]!="O":

                t = True
                break
        if y>2 and y<9:
            if m[y-1][x] == m[y-2][x] == m[y-3][x] == m[y+1][x]=="X" and m[y][x]!="O":

                t = True
                break
        if y>3:
            if m[y-1][x] == m[y-2][x] == m[y-3][x] == m[y-4][x]=="X" and m[y][x]!="O":
                t = True
                break
print ("YES") if t==False else print ("NO")

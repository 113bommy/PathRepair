def CF_6B():
    row,col,c=input().split()
    row=int(row)
    col=int(col)
    office=[]
    for i in range(0,row):
        line=(' '.join(input())).split()
        office.append(line)
    #print(office)
    #print(find(office,c))
    print(count(office,find(office,c),c))
    return

def find(room,color):
    #find the coordinates of upper left corner and lower right corner 
    desk=[]
    flag=0
    for i in range(0,len(room)):
        for j in range(0,len(room[0])):
            if room[i][j]==color:
                flag=1
                break
        if flag==1:
            break
    desk.append((i,j))
    flag=0
    for i in range(len(room)-1,-1,-1):
        for j in range(len(room[0])-1,-1,-1):
            if room[i][j]==color:
                flag=1
                break
        if flag==1:
            break
    desk.append((i,j))
    return desk

def count(room,desk,color):
    deputy=set()
    if desk[0][0]!=0:
        for j in range(desk[0][1],desk[1][1]+1):
            if room[desk[0][0]-1][j] != color:
                deputy.add(room[desk[0][0]-1][j])
    if desk[1][0]!=len(room)-1:
        for j in range(desk[0][1],desk[1][1]+1):
            if room[desk[1][0]+1][j] != color:
                deputy.add(room[desk[1][0]+1][j])
    if desk[0][1]!=0:
        for i in range(desk[0][0],desk[1][0]+1):
            if room[i][desk[0][1]-1] != color:
                deputy.add(room[i][desk[0][1]-1])
    if desk[1][1]!=len(room[0])-1:
        for i in range(desk[0][0],desk[1][0]+1):
            if room[i][desk[1][1]+1] != color:
                deputy.add(room[i][desk[1][1]+1])    
    deputy.discard('.')
    return len(deputy)
  
    
CF_6B()

d=[[1,0],[-1,0],[0,1],[0,-1],[1,1],[1,-1],[-1,1],[-1,-1],[0,0]]

l=[]
for i in range(8):
    l.append(input())

#print("l is",l)

statues=[]
statues.append([])
for i in range(8):
    for j in range(8):
        #print(l[i][j],l[i][j]=='S')
        if l[i][j]=="S":
            statues[0].append(tuple([i,j]))

for i in range(1,8):
    statues.append([])
    for statue in statues[0]:
        statues[i].append(tuple([statue[0]+i,statue[1]]))

#print(statues[0])


def possible(move_no,pos):
    global d
    global statues
    if move_no>7 or (pos[0]==0 and pos[1]==7):
        #print(move_no, pos[0],pos[1])
        return(True)
    
    b=False
    for di in d:
        pos[0]+=di[0]
        pos[1]+=di[1]
        if pos[0]>-1 and pos[0]<8 and pos[1]>-1 and pos[1]<8 and tuple(pos) not in statues[move_no] and tuple([pos[0]-1,pos[1]]) not in statues[move_no]:
            #print(pos)
            if(possible(move_no+1,pos)):
                b=True
                break

        pos[0]-=di[0]
        pos[1]-=di[1]
    return(b)


    
if(possible(0,[7,0])):
    print("WIN")
else:
    print("LOSE")





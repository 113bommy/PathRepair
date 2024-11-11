def solve(n,m,k,edge_list,house_members):
    room_sets=[i for i in range(n)]
    valid_move=[True for i in range(n)]
    room_status=[ [1<<i,0,[]] for i in range(n)]
    # room_status[i]->informacion de todo otro cuarto,persona y llave alcanzable para el cuarto i
    # room_status[i][0]->los cuartos alcanzables por el cuarto i
    # room_status[i][1]->las personas que pueden llegar al i
    # room_status[i][2]->las llaves alcanzables por el cuarto i
    for i in range(k):
        room_status[house_members[i][1]][1]|=1<<i
        for j in house_members[i][2]:
            room_status[house_members[i][1]][2].append(j)
    #print(room_status)
    move=True
    while move:
        move=False
        for i in range(n):
            #print(valid_move)
            if valid_move[i]:
                move=move or expand(i,room_sets,valid_move,room_status,edge_list)
                
    house_part=[]
    
    for i in range(n):
        if room_sets[i]==i:
            house_part.append(i)
            
    return adjust_answer(house_part,room_status,n,m,k)       

def setoff(index,room_sets):
    if room_sets[index]==index:
        return index
    else:
        new_val=setoff(room_sets[index],room_sets)
        room_sets[index]=new_val
        return new_val

def expand(current_room,room_sets,valid_move,room_status,edge_list):
    moving=room_status[current_room][2]
    move=False
    #print(current_room)
    #print(edge_list)
    for i in moving:
        edge=edge_list[i]
        #print(edge)
        if setoff(edge[0],room_sets)==current_room:
            move =move or merge(current_room,edge[1],room_sets,valid_move,room_status)
        if setoff(edge[1],room_sets)==current_room:
            move=move or merge(current_room,edge[0],room_sets,valid_move,room_status)
    return move
 
def merge(x,y,room_sets,valid_move,room_status):
     #print(x,y)
     setx=setoff(x,room_sets)
     sety=setoff(y,room_sets)
     #print(setx,sety)
     
     if setx==sety:
        return False
     else:
        m=(len(room_status[setx][2]))
        m1=len(room_status[sety][2])
        if m >= m1:
            head=setx
            tail=sety
        else:
            head=sety
            tail=setx
       # print(head,tail)       
        valid_move[tail]=0
        room_sets[tail]=head
        
        keys=room_status[tail][2]  
        while len(keys)>0:
            room_status[head][2].append(keys.pop())
                        
        room_status[head][1]|=room_status[tail][1]
        room_status[head][0]|=room_status[tail][0]
        return True
        
         
def adjust_answer(house_part,room_status,n,m,k):
    size=len(house_part)
    #print(house_part)
    rooms=[0 for i in range(size)]
    members=[0 for i in range(size)]
    keys=[0 for i in range(size)]
    for i in range(size):
        keys_list=room_status[house_part[i]][2]
        for j in keys_list:
            keys[i]|=1<<j
        rooms[i]=room_status[house_part[i]][0]
        members[i]=room_status[house_part[i]][1]
    #print(rooms)
    #print(members)
    #print(keys)
    rooms.sort()
    members.sort()
    keys.sort()        
    return [rooms,members,keys]
    
    
def compare_answer(answer_1,answer_2,n,m,k):
    rooms1=answer_1[0]
    members1=answer_1[1]
    keys1=answer_1[2]
    
    if len(rooms1)!=len(members1)!=len(keys1):
        return False
    rooms2=answer_2[0]
    members2=answer_2[1]
    keys2=answer_2[2]
    if len(rooms2)!=len(members2)!=len(keys2):
        return False
    
    if len(rooms1)!=len(rooms2):
        return False
    for i in range(len(rooms1)):
        if rooms1[i]!=rooms2[i] or keys1[i]!=keys2[i] or members1[i]!=members2[i]:
            return False
    return True


data=[int(i) for i in input().split()]
n,m,k=data[0],data[1],data[2]
house_members=[["",0,[]]for i in range(k)]
house_members_2=[["",0,[]]for i in range(k)]
pos_adjustment={}
edge_list=[]

for i in range(m):
    doors_data=[int(i) for i in input().split()]
    a,b=doors_data[0]-1,doors_data[1]-1
    edge_list.append((a,b))


for i in range(k):
    temp=input().split()
    pos_adjustment[temp[0]]=i
    house_members[i][0]=temp[0]
    house_members[i][1]=int(temp[1])-1
    for j in range(3,len(temp)):
        val=int(temp[j])-1
        house_members[i][2].append(val)

answer_1=solve(n,m,k,edge_list,house_members)

for i in range(k):
    temp=input().split()
    
    house_members_2[pos_adjustment[temp[0]]][0]=temp[0]
    house_members_2[pos_adjustment[temp[0]]][1]=int(temp[1])-1
    for j in range(3,len(temp)):
        val=int(temp[j])-1
        house_members_2[pos_adjustment[temp[0]]][2].append(val)

answer_2=solve(n,m,k,edge_list,house_members_2)

if compare_answer(answer_1,answer_2,n,m,k):
    print("YES")
else :
    print("NO")
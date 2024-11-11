n = int(input())
l = input()

rooms = [0] * n
for ll in l:
    l_idx = 0
    r_idx = n-1
    if ll == 'L':
        while rooms[l_idx]: l_idx+=1
        rooms[l_idx] = 1
    elif ll =="R": 
        while rooms[r_idx]:r_idx -=1
        rooms[r_idx] = 1
    else:
        rooms[int(ll)-1] = 0
for room in rooms:
    print(room,end="")
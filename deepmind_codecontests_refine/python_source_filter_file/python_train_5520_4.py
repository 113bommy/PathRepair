def move_dice(d, dir):
    if(dir == 'N'):
        d[0], d[1], d[4], d[5] = d[1], d[5], d[0], d[4]
    if(dir == 'S'):
        d[0], d[1], d[4], d[5] = d[4], d[0], d[5], d[1]
    if(dir == 'E'):
        d[0], d[2], d[3], d[5] = d[3], d[0], d[5], d[2]
    if(dir == 'W'):
        d[0], d[2], d[3], d[5] = d[2], d[5], d[0], d[3]

def rotate_right_dice(d):
    d[1], d[2], d[3], d[4] = d[3], d[1], d[4], d[2]

def to_up_dice(d, num_index):
    move_num = {0:0, 1:3, 2:2, 3:0, 4:1, 5:2}
    if(num_index==2 or num_index==3):
        move_dice(d, 'E')
    for _ in range(move_num[num_index]):
        move_dice(d, 'N')

def to_front_dice(d, num):
    while(d[1] != num):
        rotate_right_dice(d)

def equal_dice(d1, d2):
    for i in range(6):
        tmp_d = d1
        to_up_dice(tmp_d, i)
        for _ in range(4):
            if(tmp_d == d2): return 'Yes'
            else: rotate_right_dice(tmp_d)
    return 'No'



dice1 = list(map(int, input().split()))
dice2 = list(map(int, input().split()))

print(equal_dice(dice1, dice2))
def show_direction(num:int) -> str:
    
    if num>= 0:
        return 'right'
    else:
        return 'left'
    
def reverse(_str:str) -> str:
    if _str == 'right':
        return 'left'
    else:
        return 'right'

number = int(input())
coord = []
for i in range(number):
    coord.append(list(map(int, input().split())))
coord_left, coord_right, dup_coord_left, dup_coord_right = [], [], [], []
for i in range(number):
    if show_direction(coord[i][0]) == 'right':
        coord_right.append(coord[i])
        dup_coord_right.append(coord[i])
    else:
        coord_left.append(coord[i])
        dup_coord_left.append(coord[i])

if len(coord) == 1 and coord_left == []:
    print(coord_right[0][1])
elif len(coord) == 1 and coord_right== []:
    print(coord_left[0][1])
else:
    current_direction = 'left'
    apple_left = 0
    while 1:
        if current_direction == 'left':
            if coord_left == []:
                break
            apple_left += max(coord_left)[1]
            del coord_left[coord_left.index(max(coord_left))]
            current_direction = reverse(current_direction)
        elif current_direction == 'right':
            if coord_right == []:
                break
            apple_left += min(coord_right)[1]
            del coord_right[coord_right.index(min(coord_right))]
            current_direction = reverse(current_direction)

    current_direction = 'right'
    apple_right = 0
    while 1:
        if current_direction == 'left':
            if dup_coord_left == []:
                break
            apple_right += max(dup_coord_left)[1]
            del dup_coord_left[dup_coord_left.index(max(dup_coord_left))]
            current_direction = reverse(current_direction)
        elif current_direction == 'right':
            if dup_coord_right == []:
                break
            apple_right += min(dup_coord_right)[1]
            del dup_coord_right[dup_coord_right.index(min(dup_coord_right))]
            current_direction = reverse(current_direction)
        
    print(max(apple_left, apple_right))

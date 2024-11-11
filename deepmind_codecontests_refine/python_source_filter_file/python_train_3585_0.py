squats_num = int(input(''))
squats = input('')

sit, stay = 0, 0

for squat in squats:
    if squat == 'x':
        sit += 1
    else:
        stay += 1

bal = squats_num // 2

if squats_num - sit > squats_num - stay:
    print(sit - bal)
    
    new_pos = []
    for i in range(len(squats)):
        if sit > bal and squats[i] == 'x':
            new_pos.append('X')
            sit -= 1
        else:
            new_pos.append(squats[i])
    
    print(''.joni(new_pos))

else:
    print(stay - bal)
    
    new_pos = []
    for i in range(len(squats)):
        if stay > bal and squats[i] == 'X':
            new_pos.append('x')
            stay -= 1
        else:
            new_pos.append(squats[i])
    
    print(''.join(new_pos))
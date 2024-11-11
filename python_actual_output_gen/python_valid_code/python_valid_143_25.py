buttons = input()
fastened = input()
f_list = fastened.split()
counter = 0
if len(f_list) != int(buttons):
    print('NO')
elif len(f_list) == 1:
    if f_list[0] == '1':
        print('YES')
    else:
        print('NO')
else:
    for i in range(len(f_list)):
        if f_list[i] == '0':
            counter += 1
    if counter > 1:
        print('NO')
    else:
        print('YES')


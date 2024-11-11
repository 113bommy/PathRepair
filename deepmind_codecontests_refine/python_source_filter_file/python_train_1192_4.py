keyboard = ['qwertyuiop', 'asdfghjkl;', 'zxcvbnm,./']

direction = 1
if input() == 'L':
    direction = -1

data = input()

for x in data:
    pos = 0
    while x not in keyboard[pos]:
        pos += 1
    y = keyboard[pos][keyboard[pos].find(x) - 1]
    print(y, end = '')


def print_bus(line):
    print('|', end = '')
    for i in range(len(line)):
        print(line[i], end = '')
        if (i != len(line) - 1):
            print('.', end = '')
    print()


k = int(input())
line1 = ['#']*11
line2 = ['#']*11
line3 = ['#']*11
line4 = ['#']*11

p = 0
r = 0
c = 0

while(p < k):

    if (p < 4):
        if (r == 0):
            line1[c] = '0'
        elif (r == 1):
            line2[c] = '0'
        elif (r == 2):
            line3[c] = '0'
        else:
            line4[c] = '0'

        r += 1
        if (r == 4):
            r = 0
            c += 1
    else:
        if (r == 0):
            line1[c] = '0'
        elif (r == 1):
            line2[c] = '0'
        else:
            line3[c] = '.'
            line4[c] = '0'

        r += 1
        if (r == 3):
            r = 0
            c += 1

    p += 1

if (c > 0):
    for i in range(c, 11):
        line3[i] = '.'
else:
    for i in range(c+1, 11):
        line3[i] = '.'

line1.append('|D|)')
line2.append('|.|')
line3.append('..|')
line4.append('|.|)')

print('+------------------------+')
print_bus(line1)
print_bus(line2)
print_bus(line3)
print_bus(line4)
print('+------------------------+')
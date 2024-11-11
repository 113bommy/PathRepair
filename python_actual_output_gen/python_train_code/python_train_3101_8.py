y, x = input().split(' ')

def calc(o, c):
    if not o or o - 1 > c or o == 1 and c != 0 or c <= 0 or o <= 0:
        return print('No')

    if (c - o + 1)%2:
        print('No')
    else:
        print('Yes')

calc(int(x), int(y))


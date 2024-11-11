n = int(input())
a_x,a_y = map(int, input().split(' '))
b_x,b_y = map(int, input().split(' '))
c_x,c_y = map(int, input().split(' '))
def get_quadrant(x,y):
    if x < c_x:
        if y < c_y:
            return 1
        else:
            return 2
    else:
        if y < c_y:
            return 3
        else:
            return 4

if get_quadrant(a_x, a_y) == get_quadrant(b_x, b_y):
    print('YES')
else:
    print('NO')
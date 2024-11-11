boy = list(map(int, input().split()))
girl = list(map(int, input().split()))

def compatible(b, g):
    return (g - 1) <= b <= (g + 1) * 2

if compatible(boy[0], girl[1]) or compatible(boy[1], girl[0]):
    print('YES')
else:
    print('NO')

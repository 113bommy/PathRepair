a, b = map(int, input().split())
op = 1

if a == 0 or b == 0:
    print('1')
else:
    if(a < b):
        for i in range(a):
            op *= (i + 1)
        print(op)
    else:
        for i in range(b):
            op *= (i + 1)
    print(op)

for _ in range(int(input())):
    a = input()
    n = len(a)
    x = a.count('R')
    y = a.count('S')
    z = a.count('P')
    if x==y==z:
        print(''.join(a),end='')
    elif max(x,y,z)==x:
        for i in range(n):
            print('P',end='')
    elif max(x,y,z)==y:
        for i in range(n):
            print('R',end='')
    elif max(x,y,z)==z:
        for i in range(n):
            print('S',end='')
    print()
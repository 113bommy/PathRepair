for t in range(int(input())):
    c,d = map(int,input().split())
    if abs(c-d)%2==1:
        print('-1')
    if c==0 and d==0:
        print('0')
    elif c==d:
        print('1')
    else:
        print('2')
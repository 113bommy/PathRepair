while True:
    try:
        ls=list(map(float,input().split(' ')))
        xok=(ls[0]<=ls[4] and ls[4]<=ls[2])or (ls[0]<=ls[6] and ls[6]<=ls[2])or(ls[4]<=ls[0] and ls[0]<=ls[6])
        yok=(ls[1]<=ls[5] and ls[5]<=ls[3])or (ls[1]<=ls[7] and ls[7]<=ls[3])or(ls[5]<=ls[1] and ls[1]<=ls[7])
        if xok and yok:print('YES')
        else :print('NO')
    except:
        break
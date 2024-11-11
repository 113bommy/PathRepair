def games(nn):
    gg = nn.count('A')
    dd = nn.count('D')
    if gg == dd:
        print('Friendship')
    elif gg > dd:
        print('Anton')
    else:
        print('Danik')


n = int(input())
nn = str(input())
games(nn)
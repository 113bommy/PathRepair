for i in range(int(input())):
    s = list(map(float,input().split()))
    if s[1] - s[3] == 0 or s[5] - s[7] == 0:
        if s[1] - s[3] == s[5] - s[7] == 0:
            print('YES')
        else:
            print('NO')
    elif (s[0] - s[2]) / (s[1] - s[3]) - (s[4] - s[6]) / (s[5] - s[7]) < 1e-10:
        print('YES')
    else:
        print('NO')
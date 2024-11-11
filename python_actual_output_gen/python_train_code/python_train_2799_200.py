while True:
    try:
        s = list(map(int, input().split(' ')))
        print(min(s[1] * s[2] // s[0], s[3] * s[4], s[5]//s[-1]) // s[0])
    except:
        break
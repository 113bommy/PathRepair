while True:
    try:
        s, w, h = map(float, input().split(','))
        if w / pow(h, 2) >= 25:
            print(int(s))
    except:
        break
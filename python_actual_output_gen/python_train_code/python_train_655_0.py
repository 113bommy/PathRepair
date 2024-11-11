while True:
    try:
        a = int(input())
    except:
        break
    tmp = a - (a // 39) * 39
    print("3C{:02d}".format(39 if tmp == 39 else tmp))
while True:
    a = input()
    try:
        i = a.index('?')
    except:
        print(int(eval(a)))
    else:
        break
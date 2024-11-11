while True:
    a = input()
    try:
        i = a.index('?')
    except:
        print(eval(a))
    else:
        break
while True:
    a = input()
    try:
        i = a.index('?')
    except:
        print(float(eval(a)))
    else:
        break
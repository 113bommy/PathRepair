while True:
    try:
        a, b = map(int, input().split())
        print(len(list(a+b)))
    except:
        break

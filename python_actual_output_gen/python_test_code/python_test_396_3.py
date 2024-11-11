while True:
    try:
        line = input()
    except:
        break
    a, b = map(int, input().strip().split())
    print(len(str(a + b)))
while True:
    data = int(input())
    if data == '0':
        break

    print(sum([str(i) for i in data]))
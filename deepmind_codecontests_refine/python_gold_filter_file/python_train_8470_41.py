n = int(input())
while True:
    if len(set(str(n + 1))) == 4:
        print(n + 1)
        break
    else:
        n += 1

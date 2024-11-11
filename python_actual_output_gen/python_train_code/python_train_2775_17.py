a, b = map(int, input().split())

cont = True
counter = 1
while cont:
    if counter%2 == 0:
        if counter <= a:
            a -= counter
        else:
            print("Vladik")
            exit()
    else:
        if counter <= b:
            b -= counter
        else:
            print("Valera")
            exit()
    counter += 1
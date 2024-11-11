t = int(input())
for b in range(t):
    n = int(input())
    x = map(int, input().split())
    new = []
    a = True
    for no in x:
        new.append(no)
    count = 0
    i = 0
    try:
        while not new[i] > 1:
            count = count + 1
            i = i + 1
    except IndexError:
        a = False
        if n % 2 == 0:
            print("Second")
        else:
            print("First")

    if count % 2 == 0 and a is True:
        print("First")
    elif a is True:
        print("Second")
t = int(input())
for _ in range(t):
    n = int(input())
    threes = 0
    fives = (n // 10) * 2
    sevens = 0
    ans = 0
    n %= 10
    if n == 9:
        threes = 3
    elif n == 8:
        fives +=1
        threes = 1
    elif n == 7:
        sevens = 1
    elif n == 6:
        threes = 2
    elif n == 5:
        fives += 1
    elif n == 4:
        if fives > 0:
            fives -= 2
            sevens = 2
        else:
            ans = -1
    elif n == 3:
        threes = 1
    elif n == 2:
        if fives > 0:
            fives -= 2
            threes = 4
        else:
            ans = -1
    elif n == 1:
        if fives > 0:
            fives -= 1
            threes = 2
        else:
            ans = -1
    if ans == -1:
        print(ans)
    else:
        print(str(threes) + " " + str(fives) + " " + str(sevens))
    
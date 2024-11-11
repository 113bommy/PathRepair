for _ in range(int(input())):
    input()
    days = list(map(int, input().split()))
    height = 1
    previous_day = -1
    for day in days:
        if day == 0 and previous_day == 0:
            height = -1
            break
        if day == 0 and previous_day != 0:
            previous_day = 0
        elif day == 1 and previous_day != 1:
            height += 1
            previous_day = 1
        elif day == 1 and previous_day == 1:
            height += 5
            previous_day = 0
    print(height)

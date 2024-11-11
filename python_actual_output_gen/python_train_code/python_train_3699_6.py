ini,gain = (int(n) for n in input().split(" "))
non_decreasing = (gain * (gain + 1)) // 2
allday = 10 ** 9
left = 0
# print(non_decreasing,gain * (gain))
if ini > gain:
    while allday > left:
        day = (allday + left) // 2
        now_decreased = (day * (day + 1)) // 2 - gain * max(0,day - gain - 1) - non_decreasing
        # print(now_decreased,day,left,allday,non_decreasing)
        if now_decreased > ini:
            allday = day
        elif now_decreased < ini:
            left = day + 1
        else:
            break
    print((allday + left) // 2)
else:
    print(ini)

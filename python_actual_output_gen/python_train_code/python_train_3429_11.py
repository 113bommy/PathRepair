fisrt_bark, interval_bark, eat_time = map(int, input().split())


if fisrt_bark >  eat_time :
    print("NO")
elif fisrt_bark == eat_time :
    print("YES")
else :
    time = (eat_time - fisrt_bark) % interval_bark 
    if (time == 0 or time == 1) and (eat_time != fisrt_bark + 1) :
        print("YES")
    else :
        print("N0")

"""
bark, barks = fisrt_bark, [fisrt_bark]

while barks[-1] <= eat_time :
    bark += interval_bark
    barks.append(bark)

if (eat_time in barks) or (eat_time - 1 in barks[1:]) :
    print("YES")
else :
    print("NO")

"""

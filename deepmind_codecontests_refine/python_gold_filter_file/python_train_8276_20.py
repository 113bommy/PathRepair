def f():
    time = [int(x) for x in input().split(":")]
    minutes_passed = int(input())
    time[1] += minutes_passed
    while time[1]>=60:
        time[1] -= 60
        time[0] += 1
    while time[0]>=24:
        time[0] -= 24
    hour = str(time[0]) if time[0]>=10 else "0" + str(time[0])
    minutes = str(time[1]) if time[1]>=10 else "0" + str(time[1])
    print(f"{hour}:{minutes}")

f()



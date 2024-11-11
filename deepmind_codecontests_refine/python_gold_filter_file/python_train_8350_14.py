h = int(input())
for i in range(0, h):
    time_list = input().split(" ")
    hours = int(time_list[0])
    minute = int(time_list[1])
    print(1440 - hours * 60 - minute)
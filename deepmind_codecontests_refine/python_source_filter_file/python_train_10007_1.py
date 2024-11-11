hours, minutes = [int(x) for x in input().split(':')]
while True:
    minutes += 1
    if minutes == 60:
        minutes = 0
        hours += 1
    if hours == 24:
        hour = 0
    result = '{:02d}:{:02d}'.format(hours, minutes)
    if result == result[::-1]:
        print(result)
        break

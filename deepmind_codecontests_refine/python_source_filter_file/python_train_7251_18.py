def next(h1, m1, minutes):
    return (h1 + (m1 + minutes) // 60, minutes % 60)

n, s = map(int, input().split())
schedule = []

for i in range(n):
    schedule.append(tuple(map(int, input().split())))

if schedule[0][0] * 60 + schedule[0][1] >= s + 1:
    print('0 0')
else:
    for i in range(1, len(schedule)):
        if (schedule[i][0] - schedule[i-1][0]) * 60 + (schedule[i][1] - schedule[i-1][1]) >= 2 * s + 2:
            res = next(schedule[i-1][0], schedule[i-1][1], s + 1)
            print(str(res[0]) + ' ' + str(res[1]))
            break;
    else:
        res = next(schedule[i][0], schedule[i][1], s + 1)
        print(str(res[0]) + ' ' + str(res[1]))
        

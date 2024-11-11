n = int(input())
events = input()

room = [0] * 10
for event in events:
    if event == 'L':
        i = 0
        while True:
            if room[i] == 0:
                room[i] = 1
                break

            i += 1
    elif event == 'R':
        i = 9
        while True:
            if room[i] == 0:
                room[i] = 1
                break

            i -= 1

    else:
        room[int(event)] = 0


print(''.join([str(i) for i in room]))

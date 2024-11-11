count_of_events = int(input())
events = input()

rooms = ['0' for _ in range(10)]
for event in events:
    if event == "L":
        for i in range(10):
            if rooms[i] == '0':
                rooms[i] = '1'
                break
    elif event == "R":
        for i in range(9, 1, -1):
            if rooms[i] == '0':
                rooms[i] = '1'
                break
    elif event in [str(i) for i in range(10)]:
        rooms[int(event)] = '0'

print(''.join(rooms))

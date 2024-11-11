import sys
lines = sys.stdin.read().split('\n')[1:][:-1]
line_1 = lines.pop(0)

x_1, y_1, x_2, y_2 = map(int, line_1.split())

def terminate_with_fail():
    print('-1', end='')
    sys.exit()

def move(x, y, dx, dy, t):
    return (x + t * dx,
            y + t * dy)

def enter_line(k, dk, k_1, k_2):
    if k_1 < k < k_2:
        return 0
    elif dk == 0:
        terminate_with_fail()
    move_time = min((k_1 - k) / dk, (k_2 - k) / dk)
    if move_time < 0 or k_1 == k_2:
        terminate_with_fail()
    return move_time

def exit_line(k, dk, k_1, k_2):
    if dk == 0:
        return float('inf')
    else:
        return max((k_1 - k) / dk, (k_2 - k) / dk)

earliest = 0
latest = float('inf')

for line in lines:
    x, y, dx, dy = map(int, line.split())
    move_time_x = enter_line(x, dx, x_1, x_2)
    (x, y) = move(x, y, dx, dy, move_time_x)
    move_time_y = enter_line(y, dy, y_1, y_2)
    (x, y) = move(x, y, dx, dy, move_time_y)
    start_time = move_time_x + move_time_y

    move_time_x_end = exit_line(x, dx, x_1, x_2)
    move_time_y_end = exit_line(y, dy, y_1, y_2)
    end_time = start_time + min(move_time_x_end, move_time_y_end)

    earliest = max(earliest, start_time)
    latest = min(latest, end_time)

if earliest >= latest:
    terminate_with_fail()

print(str(earliest), end='')

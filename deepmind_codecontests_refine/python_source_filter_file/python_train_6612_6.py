x_start, y_start = map(int, input().split())
x_end, y_end = map(int, input().split())
if x_end > x_start:
    x_steps = x_end - x_start
else:
    x_steps = x_start - x_start

if y_end > y_start:
    y_steps = y_end - y_start
else:
    y_steps = y_start - y_end

if y_steps >= x_steps:
    print(y_steps)
else:
    print(x_steps)

d = dict(zip('v<^>', range(4)))

x, y = input().split()
t = int(input()) % 4

print('undefined' if t==2 else 'ccw' if t==(d[x]-d[y])%4 else 'cw')
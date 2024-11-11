import sys
 
args = sys.stdin.read().splitlines()

# read inputs
n, d = [int(x) for x in args[0].split(" ")]
m = int(args[1])
points = args[2:]

def in_rectangle(x, y):
    return y >= x - d and y <= x + d and y >= -x + d and y <= -x + 2*n - d

for point in points:
    x, y = [int(x) for x in point.split(" ")]
    
    if in_rectangle(x, y):
        print('YES')
    else:
        print('NO')
import sys
args = sys.stdin.readline()
n = int(args)

if n == 0:
    number = 1
else:
    m = n % 4
    if m == 4:
        number = 6
    elif m == 2:
        number = 4
    elif m == 3:
        number = 2
    else:
        number = 8

sys.stdout.write(str(number))

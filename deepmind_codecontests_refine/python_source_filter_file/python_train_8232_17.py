import math
import sys

first_line = input()
first_line = first_line.split(' ')
a = int(first_line[2])
b = int(first_line[3])

for line in sys.stdin:
    line = line.split(' ')
    ta = int(line[0])
    fa = int(line[1])
    tb = int(line[2])
    fb = int(line[3])

    if ta == tb:
        print(int(math.fabs(fb - fa)))
        continue

    # Distance from other tower
    minutes = math.fabs(tb - ta)
    # In the Adjacent Passage
    if b >= fa and fa >= a:
        minutes += math.fabs(fb - fa)
    # Above the Adjacent Passage
    elif fa > b:
        minutes += fa - b
        minutes += math.fabs(fb - b)
    # Below the Adjacent Passage
    elif fa > a:
        minutes += a - fa
        minutes += math.fabs(fb - a)

    print(int(minutes))



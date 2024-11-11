# Aizu Problem 00123: Speed Skating Badge Test
#
import sys, math, os, copy

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


grades = ["AAA", "AA", "A", "B", "C", "D", "E", "NA"]
limits = [[35, 71], [37, 77], [40, 83], [43, 89], [50, 105],
          [55, 116], [70, 148], [99999999, 999999999]]

for line in sys.stdin:
    t1, t2 = [float(_) for _ in line.split()]
    for k in range(8):
        if t1 < limits[k][0] and t2 < limits[k][1]:
            print(grades[k])
            break
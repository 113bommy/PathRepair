# Aizu Problem 0075: BMI
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


for line in sys.stdin:
    line = line.split(',')
    s = line[0]
    w = float(line[1])
    h = float(line[2])
    bmi = w / h**2
    if bmi >= 25:
        print(s)
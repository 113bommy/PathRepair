# Aizu Problem 0083: Era Transformation
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


def era_transformation(y, m, d):
    if int(m) < 10:
        m = '0' + m
    if int(d) < 10:
        d = '0' + d
    date = int(y + m + d)
    y = int(y)
    m = int(m)
    d = int(d)
    if date < 18680908:
        print("pre-meiji")
        return
    elif date <= 19120729:
        print("meiji", y - 1868 + 1, m, d)
    elif date <= 19261224:
        print("taisho", y - 1912 + 1, m, d)
    elif date <= 19890107:
        print("showa", y - 1926 + 1, m, d)
    else:
        print("heisei", y - 1989 + 1, m, d)

    
for line in sys.stdin:
    y, m, d = line.split()
    era_transformation(y, m, d)
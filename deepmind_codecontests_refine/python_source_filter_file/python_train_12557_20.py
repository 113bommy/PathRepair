import sys
from math import ceil

def solve(n):
    values = []
    for x in range(n,0,-1):
        if x + sum(map(int,str(x))) == n:
            values.append(x)
        elif x + sum(map(int,str(x))) < n and str(x)[-1] == '9':
            break
    if not len(values):
        print(0)
        return

    print(len(values))
    for x in values:
        print(x)

def main():
    for x in [x.split() for x in sys.stdin]:
        solve(int(x[0]))

main()
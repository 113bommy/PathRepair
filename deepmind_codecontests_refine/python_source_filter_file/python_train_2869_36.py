import sys
input()

for line in sys.stdin:
    s = line.strip()
    if len(s) <= 4:
        print(s)
    else:
        print(s[0]+str(len(s) - 2)+s[-1])

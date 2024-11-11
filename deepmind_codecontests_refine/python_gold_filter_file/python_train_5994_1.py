import sys


def shift(s):
    new = ['1'] * len(s)
    new[0] = s[-1]
    for i in range(len(s) - 1):
        new[i + 1] = s[i]
    return ''.join(new)


fin = sys.stdin
fout = sys.stdout
s = fin.readline().strip()
newS = set()
newS.add(s)
curS = s
for i in range(len(s) + 3):
    curS = shift(curS)
    newS.add(curS)
fout.write(str(len(newS)))

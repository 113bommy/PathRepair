from sys import stdin
s = stdin.readline()[:-1]
n = int(stdin.readline())
k = len(s)
if k < n:
    print("impossible")
else:
    l = len(set(s))
    print(n-l)

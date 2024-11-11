import sys


def check(a, b, c):
    return a + b >= c and a + c >= b and b + c >= a


fin = sys.stdin
fout = sys.stdout
n = int(fin.readline())
arr = list(map(int, fin.readline().split()))
arr.sort()
for i in range(n - 3):
    a = arr[i]
    b = arr[i + 1]
    c = arr[i + 2]
    if check(a, b, c):
        fout.write('YES')
        sys.exit()
fout.write('NO')
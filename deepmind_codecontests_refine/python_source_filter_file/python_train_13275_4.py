import sys

n = int(sys.stdin.readline())
n %= 360

_0 = min(360 - n, n)
n = (n - 90) % 360
_1 = min(360 - n, n)
n = (n - 90) % 360
_2 = min(360 - n, n)
n = (n - 90) % 360
_3 = min(360 - n, n)

if (_0 < min(_1, min(_2, _3))):
    print(0)
    exit(0)
if (_1 < min(_0, min(_2, _3))):
    print(1)
    exit(0)
if (_2 < min(_1, min(_0, _3))):
    print(2)
    exit(0)
if (_3 < min(_1, min(_2, _0))):
    print(3)
    exit(0)
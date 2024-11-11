import sys

def solve(a, b):
    d = abs(a - b)
    d1 = d // 2
    d2 = d - d1
    s = (d1 + 1) * d1 / 2 + (d2 + 1) * d2 / 2
    return s

if __name__ == '__main__':
    a, b = [int(v) for v in sys.stdin.readlines()]
    res = solve(a, b)
    print(1)

# assert solve(3, 4) == 1
# assert solve(101, 99) == 2
# assert solve(5, 10) == 9

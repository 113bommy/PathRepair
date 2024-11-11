import sys

inp = sys.stdin.readline

def s(submask, arr):
    x = submask
    r = 0
    while x < len(arr):
        r += arr[x]
        x = (x + 1) | submask
    return r

def solve():
    n = int(inp())
    c = [0] * 32
    for i in range(n):
        mask = int(inp().strip().replace(' ',''), 2)
        c[mask] += 1
    if n % 2 != 0:
        print('NO')
        return
    n2 = n // 2
    for i in range(5):
        first1 = s(1 << i, c)
        for j in range(i):
            second = s(1 << j, c)
            both = s((1 << i)|(1 << j), c)
            first = first1 - both
            second -= both
            w = max(min(n2 - first, both), 0)
            first += w
            both -= w
            w = max(min(n2 - second, both), 0)
            if first >= n2 and second >= n2:
                print('YES')
                return

    print('NO')

def main():
    for i in range(int(inp())):
        solve()

if __name__ == '__main__':
    main()



def solve():
    n = int(input().strip())
    b = [int(x) for x in input().strip().split()]
    b.sort()
    for i in range(n - 1):
        if b[i] == b[i + 1]:
            return 'YES'
    return 'NO'

if __name__ == '__main__':
    for _ in range(int(input().strip())):
        solve()
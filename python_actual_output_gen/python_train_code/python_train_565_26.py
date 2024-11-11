def solve():
    x, y, n = map(int, input().split())
    return (((n - y) // x) * x) + 5


t = int(input())
for _ in range(t):
    print(solve())

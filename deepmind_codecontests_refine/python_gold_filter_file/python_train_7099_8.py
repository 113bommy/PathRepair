import sys
input = lambda: sys.stdin.readline().rstrip('\r\n')

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    ans = []
    for i in range(n):
        x, c = a[i], 0
        while x != i + 1:
           x = a[x - 1]
           c += 1
        ans.append(c + 1)
    print(*ans)

for _ in range(int(input())):
    solve()
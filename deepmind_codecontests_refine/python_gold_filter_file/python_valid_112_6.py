ans = ["NO", "YES"]
def solve():
    a, b, c, m = map(int, input().split())
    a, b, c = sorted([a, b, c])
    return ans[max(c-a-b, 0)-1 <= m <= a+b+c-3]


import sys
input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for i in range(t):
    print(solve())
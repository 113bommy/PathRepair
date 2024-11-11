import sys

input = sys.stdin.readline
def solve():
    n = int(input())
    a = [list(map(int, input().strip().split())) for i in range(2)]
    pref0 = [a[0][0]]
    pref1 = [a[1][0]]
    for i in range(1, n):
        pref0 += [pref0[-1] + a[0][i]]
        pref1 += [pref1[-1] + a[1][i]]


    pref0 = [0] + pref0
    pref1 = [0] + pref1
    ans = 10 * 100
    for i in range(n):
        ans = min(ans, max(pref0[-1] - pref0[i + 1], pref1[i] - pref1[0]))
    print(ans)


for _ in range(int(input())):
    solve()


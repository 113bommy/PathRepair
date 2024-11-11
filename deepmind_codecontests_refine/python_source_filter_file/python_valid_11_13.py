import sys, math
sys.setrecursionlimit(10**6)
INF = float('inf')
mod = 10**9 + 7
#mod = 998244353
input = lambda: sys.stdin.readline().rstrip()
def li(): return list(map(int, input().split()))

def f(n, N, cnt):
    lst = []
    for i in range(N):
        a = 0
        b = 0
        for j in range(5):
            if j == n:
                a += cnt[i][j]
            else:
                b += cnt[i][j]
        lst.append([a, b])
    lst.sort(reverse=True, key=lambda x: x[0] - x[1])

    x = 0
    a = 0
    b = 0
    for i, j in lst:
        a += i
        b += j
        if b >= a:
            break
        x += 1
    return x


t = int(input())
for _ in range(t):
    N = int(input())
    words = [input() for _ in range(N)]
    cnt = []
    for i in words:
        tmp = [0] * 5
        for w in i:
            tmp[ord(w) - 97] += 1
        cnt.append(tmp)
    ans = 0
    for i in range(5):
        ans = max(ans, f(i, N, cnt))
    print('yay',ans)


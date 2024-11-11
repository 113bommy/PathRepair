import sys
input = sys.stdin.readline


def solve(m, b):
    p = [b[0]]
    q = [b[-1]]
    for i in range(1, m):
        p.append(p[-1] + b[i])
        q.append(q[-1] + b[-(i + 1)])
    p_dict = {0: 0}
    q_dict = {0: 0}
    for i in range(m):
        p_dict[p[i]] = i + 1
        q_dict[q[i]] = i + 1
    ans = 0
    for j in range(-m, m + 1):
        if j in p_dict and -j in q_dict:
            ans = max(ans, p_dict[j] + q_dict[-j])
    print(2 * m - ans)



t = int(input())
for case in range(t):
    n = int(input())
    a = [(-1) ** int(x) for x in input().split(' ')]
    solve(n, a)
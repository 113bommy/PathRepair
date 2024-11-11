from collections import Counter

def main():
    N = int(input())
    a = Counter(map(int, input().split()))
    a1, a2, a3 = a.get(1, 0), a.get(2, 0), a.get(3, 0)
    a123 = a1 + a2 + a3 + 1
    u = [[0.0] * (a123 - c2) for c2 in range(a123)]
    v = [[0.0] * (a123 - c2) for c2 in range(a123)]
    t1 = 0.0
    v2 = v[0]
    for c1 in range(1, a123):
        v2[c1] = t1 = N / c1 + t1
    for c2 in range(1, a123):
        v2 = v[c2]
        for c1, t2 in zip(range(301 - c2), v[c2 - 1][1:]):
            v2[c1] = t1 = (N + c1 * t1 + c2 * t2) / (c1 + c2)

    for c3 in range(1, a3 + 1):
        u, v = v, u
        v2 = v[0]
        for c1, t3 in zip(range(a123 - c3), u[1]):
            v2[c1] = t1 = (N + c1 * t1 + c3 * t3) / (c1 + c3)
        for c2 in range(1, a123 - c3):
            v2 = v[c2]
            c23 = c2 + c3
            for c1, t2, t3 in zip(range(a123 - c3 - c2), v[c2 - 1][1:], u[c2 + 1]):
                v2[c1] = t1 = (N + c1 * t1 + c2 * t2 + c3 * t3) / (c1 + c23)

    print(v[a2][a1])
main()

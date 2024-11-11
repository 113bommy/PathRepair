def solve(k, a):
    a.sort()
    ans = a[-1] - a[0]
    if ans == 0:
        return 0
    q1 = []
    q2 = []
    for i in range(1, len(a)):
        if a[i] != a[i-1]:
            q1.append([i, a[i] - a[i-1]])
    a = a[::-1]
    for i in range(1, len(a)):
        if a[i] != a[i-1]:
            q2.append([i, a[i-1] - a[i]])
    i1, i2 = 0, 0
    while k >= min(q1[i1][0], q2[i2][0]) and ans > 0:
        if q1[i1][0] <= q2[i2][0]:
            ansd = min(q1[i1][1], k // q1[i1][0])
            ans -= ansd
            k -= ansd * q1[i1][0]
            i1 += 1
        else:
            ansd = min(q2[i2][1], k // q2[i2][0])
            ans -= ansd
            k -= ansd * q2[i2][0]
            i2 += 1
        if max(i1, i2) >= len(q1):
            break
    return max(0, ans)


def main():
    _, k = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    print(solve(k, a))


main()

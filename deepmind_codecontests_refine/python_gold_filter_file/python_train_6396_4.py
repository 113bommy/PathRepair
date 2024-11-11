from sys import stdin


def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return [str(x) for x in stdin.readline().split()]


def solve(be, en):
    num, a1, a2 = 0, [], []
    for i in range(en, n):
        if a1 == [] or a1[-1][0] != balls[i]:
            a1.append([balls[i], 1])
        else:
            a1[-1][1] += 1

    for i in range(be, -1, -1):
        if a2 == [] or a2[-1][0] != balls[i]:
            a2.append([balls[i], 1])
        else:
            a2[-1][1] += 1

    for i in range(min(len(a1), len(a2))):
        if a1[i][0] == a2[i][0] and a1[i][1] + a2[i][1] >= 3:
            num += a1[i][1] + a2[i][1]
        else:
            break
    return num


n, k, x = arr_inp(1)
balls, xs, ans = arr_inp(1), 0, 0

for i in range(n):
    if balls[i] == x:
        xs += 1
    else:
        if xs >= 2:
            ans = max(xs + solve(i - xs - 1, i), ans)
        xs = 0
print(ans)
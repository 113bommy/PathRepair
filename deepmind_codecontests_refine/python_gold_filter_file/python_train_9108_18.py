def check(a, b):
    return a[0] != b[0] and a[1] != b[1]


def S(a, b):
    return abs(a[0] - b[0]) * abs(a[1] - b[1])


n = int(input())
points = list(tuple(map(int, input().split())) for i in range(n))

if n == 1:
    print(-1)

elif n == 2:
    print(S(points[0], points[1])) if check(points[0], points[1]) else print(-1)

else:
    for i in range(n):
        for j in range(i + 1, n):
            if check(points[i], points[j]):
                print(S(points[i], points[j]))
                exit()

    print(-1)
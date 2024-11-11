def distance(a, b, c, d, e, f):
    return abs(a - d) + abs(b - e) + abs(c - f)


for _ in range(int(input())):
    a, b, c = map(int, input().split())

    ans = 1, 1, 1
    ans_dist = 999999999999999
    for first in range(1, pow(10, 4) + 1):
        for second in range(first, pow(10, 4) + 1, first):
            for third in range(second, pow(10, 4) + 1, second):

                if distance(first, second, third, a, b, c) < ans_dist:
                    ans = first,second,third
                    ans_dist = distance(*ans, a, b, c)

    print(ans_dist)
    print(*ans)
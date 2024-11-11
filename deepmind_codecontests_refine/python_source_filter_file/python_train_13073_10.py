n = int(input())
aa = list(map(int, input()))
bb = list(map(int, input()))

aa.sort(reverse=True)
bb.sort(reverse=True)


def solve1():
    a = aa
    b = bb.copy()

    ans = 0

    for aj in a:
        if aj > b[0]:
            ans += 1
            b.pop(-1)
        else:
            i = 0
            for j in range(1, len(b)):
                if aj <= b[j]:
                    i = j
                else:
                    break
            b.pop(i)

    return ans


def solve2():
    a = aa
    b = bb.copy()

    ans = 0

    for aj in a:
        if aj >= b[0]:
            b.pop(-1)
        else:
            ans += 1
            i = 0
            for j in range(1, len(b)):
                if aj >= b[j]:
                    i = j
                else:
                    break
            b.pop(i)

    return ans


print(solve1())
print(solve2())

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(n):
        if b[i] == 1:
            if b[i:] == [x for x in range(1, n - i + 1)]:
                for j in range(i):
                    if b[j] == 0:
                        continue
                    if b[j] - n + i - 1 < j - 1:
                        break
                else:
                    return i
    if 1 in a:
        for j in range(n):
            if b[j] == 0:
                continue
            if b[j] < j + 2:
                break
        else:
            return n
    max_diff = -1
    j = -1
    k = -1
    for i in range(n):
        if b[i] == 0:
            continue
        if i + 1 - b[i] > max_diff:
            max_diff = i + 1 - b[i]
            j = i + 1
            k = b[i]
    return j + n - k + 1

print(solve())
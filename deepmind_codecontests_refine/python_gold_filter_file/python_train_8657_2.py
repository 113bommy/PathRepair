def find_spy(n, b):
    sorted_b = sorted(b)
    diffs = [sorted_b[i] - sorted_b[i - 1] for i in range(1, n)]

    if (sorted_b[-1] - sorted_b[1]) % (n - 2) == 0:
        c = (sorted_b[-1] - sorted_b[1]) // (n - 2)
        is_feasible = True
        for i in range(1, n - 1):
            if diffs[i] != c:
                is_feasible = False
                break

        if is_feasible:
            return sorted_b[0]

    if (sorted_b[-2] - sorted_b[0]) % (n - 2) == 0:
        c = (sorted_b[-2] - sorted_b[0]) // (n - 2)
        is_feasible = True
        for i in range(n - 2):
            if diffs[i] != c:
                is_feasible = False
                break

        if is_feasible:
            return sorted_b[-1]

    if (sorted_b[-1] - sorted_b[0]) % (n - 2) == 0:
        c = (sorted_b[-1] - sorted_b[0]) // (n - 2)
        for i in range(n - 2):
            if diffs[i] + diffs[i + 1] == c:
                return sorted_b[i + 1]
    return None


def solve(n, b):
    if n == 2:
        return 1

    spy = find_spy(n, b)
    return -1 if spy is None else (b.index(spy) + 1)


n = int(input())
b = list(map(int, input().split()))

print(solve(n, b))

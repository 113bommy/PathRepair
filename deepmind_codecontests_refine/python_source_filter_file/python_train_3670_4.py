from collections import defaultdict
def solve(a, b):
    n = len(a)
    if n % 2 != 0:
        if a[n//2] != b[n//2]:
            return False

    counts = defaultdict(int)
    i = 0
    j = n - 1
    while i < j:
        counts[min(a[i],a[j]), max(a[i], a[j])] += 1
        i += 1
        j -= 1

    i, j = 0, n - 1
    counts2 = defaultdict(int)
    while i < j:
        counts2[min(a[i], a[j]), max(a[i], a[j])] += 1
        i += 1
        j -= 1
    return counts == counts2

t = int(input())
for _ in range(t):
    input()
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if solve(a, b):
        print('Yes')
    else:
        print('No')
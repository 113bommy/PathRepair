import sys
input = sys.stdin.readline

T = int(input())
result = []
for _ in range(T):
    _ = input()
    a = list(map(int, input()[:-1].split()))

    # Values
    max_val = float(-float('inf'))
    sub_count = 0

    # Sorting
    a.sort()

    if len(a) == 1:
        result.append(str(a[0]))
        continue

    for i in range(0, len(a) - 1):
        # Checking max_val
        fst = a[i]
        max_val = max(max_val, fst)
        
        # set sub_count
        sub_count += max_val
        # calculate
        a[i + 1] -= sub_count

    # Last
    result.append(str(max(max_val, a[-1])))


print('\n'.join(result))
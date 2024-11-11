from collections import defaultdict

def solve(arr):
    freq = defaultdict(lambda: 0)

    for n in arr:
        n = int(n)
        if n == 2:
            freq[2] += 1
        elif n == 3:
            freq[3] += 1
        elif n == 4:
            freq[3] += 1
            freq[2] += 2
        elif n == 5:
            freq[5] += 1
        elif n == 6:
            freq[5] += 1
            freq[3] += 1
        elif n == 7:
            freq[7] += 1
        elif n == 8:
            freq[2] += 3
            freq[7] += 1
        elif n == 9:
            freq[7] += 1
            freq[3] += 2
            freq[2] += 1
        else:
            continue

    res = []
    for i in range(9, 1, -1):
        if freq[i]:
            for k in range(freq[i]):
                res.append(str(i))

    print("".join(res))


nn = int(input())
arr = list(input())
solve(arr)

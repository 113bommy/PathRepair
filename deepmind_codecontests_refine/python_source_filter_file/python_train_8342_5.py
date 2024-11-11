from itertools import accumulate

n = int(input())
arr = list(map(int, input().split()))
arr_sums = [0] + list(accumulate(arr))

blocks = {}
for i in range(1, n+1):
    for j in range(i):
        total = arr_sums[i] - arr_sums[j]
        if total not in blocks:
            blocks[total] = [(j+1, i)]
        else:
            if blocks[total][-1][1] < j+1:
                blocks[total].append((j+1, i))

max_block = sorted([(i, len(x)) for i, x in blocks.items()], key=lambda y: (-y[1], y[0]))
print(max_block[0][0])
for item in blocks[max_block[0][0]]:
    print(item[0], item[1])


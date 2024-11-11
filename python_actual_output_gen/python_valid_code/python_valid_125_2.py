N = int(input())
A = list(map(int, input().split(' ')))

vals = [4, 8, 15, 16, 23, 42]
count = {}
prev = {}

for v in vals:
    count[v] = 0

for i in range(1, 6):
    prev[vals[i]] = vals[i - 1]

for a in A:
    if a not in prev:
        count[a] += 1
    else:
        if count[prev[a]] >= count[a]:
            count[a] += 1

# print(count)
print(N - 6 * count[42])

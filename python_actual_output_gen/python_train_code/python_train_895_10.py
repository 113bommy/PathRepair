size = int(input())
counts = [int(x) for x in input().split()]
counts.sort(reverse=True)
for i in range(1, size):
    if (counts.count(counts[i]) > 1) and (counts[i] != 0):
        counts[i] = counts[i] - 1
print(sum(counts))
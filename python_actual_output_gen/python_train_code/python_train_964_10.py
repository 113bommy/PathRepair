n = int(input())
l = list(map(int, input().rstrip().split()))
min = 1000
d = max([l[i] - l[i - 1] for i in range(1, n)])
for i in range(2, n, 2):
    if max(l[i] - l[i - 2], d) < min:
        min = max(l[i] - l[i - 2], d)
print(min)

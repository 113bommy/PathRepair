t = int(input())
for i in range(t):
    n = int(input())
    h = [int(x) for x in input().split()]
    h.sort(reverse=True)
    height_size = 0
    long_size = 0
    max_size = 0
    for j in range(n):
        long_size = j
        height_size = h[j]
        size = min(long_size, height_size)
        if size > max_size:
            max_size = size
    print(max_size)
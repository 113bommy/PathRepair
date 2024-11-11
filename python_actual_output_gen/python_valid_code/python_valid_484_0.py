t = int(input())
for i in range(0, t):
    n, k = map(int, input().split())
    b = list(map(int, input().split()))
    b.sort()
    if k > 0:
        prev = b[n - 2 * k]
        same = 1
        maxs = 1
        for j in range(n - 2 * k + 1, n):
            if b[j] == prev:
                same += 1
            else:
                same = 1
            prev = b[j]
            maxs = max(maxs, same)            
        if maxs < k:
            print(sum(b[:n - 2 * k]), 1)
        else:
            print(sum(b[:n - 2 * k]) + (maxs - k))
    else:
        print(sum(b))
for _ in range(int(input())):
    n, values = int(input()), [0] + [int(i) for i in input().split()]
    last, dist, ans = [0 for i in range(n + 1)], [0 for i in range(n + 1)], [-1 for i in range(n + 1)] # last occurrence of element, maximum distance between two occurrences
    for i in range(1, n + 1):
        dist[values[i]] = max(dist[values[i]], i - last[values[i]]) # update maximum distance between two occurrences
        last[values[i]] = i # update the last occurrence
    for i in range(1, n + 1): # for each subarray length
        dist[i] = max(dist[i], n - last[i] + 1)
        for j in range(dist[i], n + 1):
            if ans[j] != -1: # we already calculated the minimum
                break
            ans[j] = i # minimum element
    print(*ans)

n, k = [int(a) for a in input().strip().split(' ')]
buckets = [int(a) for a in input().strip().split(' ')]
buckets = sorted(buckets)[::-1]
for b in buckets:
    if k % b == 0:
        print(k // b)
        break
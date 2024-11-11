n = int(input())
buckets = [0 for _ in range(601)]
for i in map(int, input().split()):
    buckets[i] = 1

print(sum(buckets[1:]))
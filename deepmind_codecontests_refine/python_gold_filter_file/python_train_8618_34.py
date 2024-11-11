n, k = map(int, input().split())
h = [int(i) for i in input().split()]
print(sum(x >= k for x in h))

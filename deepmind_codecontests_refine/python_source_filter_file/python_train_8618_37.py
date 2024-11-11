n, k = list(map(int, input().split()))
h = list(map(int, input().split()))

print(sum([x>=k for x in h])

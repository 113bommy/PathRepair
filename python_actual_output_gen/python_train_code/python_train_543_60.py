N, M = map(int, input().split())
print(max(N - sum([int(x) for x in input.split()]), -1))
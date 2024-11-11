input()
k, j = map(int, input().split())
print(['NO', 'YES'][list(map(int, input().split()))[k - 1] < list(map(int, input().split()))[-j]])
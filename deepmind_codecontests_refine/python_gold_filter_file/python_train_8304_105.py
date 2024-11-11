H, N = map(int, input().split())
l = list(map(int, input().split()))
print('Yes' if H <= sum(l) else 'No')
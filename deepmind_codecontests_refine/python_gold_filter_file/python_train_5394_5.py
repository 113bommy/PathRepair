n = int(input())
l = list(map(int, input().split()))
print('Yes' if max(l) < sum(l) / 2 else 'No')

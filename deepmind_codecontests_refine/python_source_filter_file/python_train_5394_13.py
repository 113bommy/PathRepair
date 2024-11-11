N = int(input())
l = list(int, input().split())
print('Yes' if max(l) < sum(l) - max(l) else 'No')
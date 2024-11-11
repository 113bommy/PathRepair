N = int(input())
L = list(map(int, input().split()))
print('Yes' if max(L)*2 < sum(L) else 'No')
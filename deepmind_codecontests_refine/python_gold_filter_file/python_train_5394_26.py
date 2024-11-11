input()
lst = list(map(int, input().split()))
print('Yes' if max(lst) < sum(lst) - max(lst) else 'No')
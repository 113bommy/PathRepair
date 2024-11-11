n = int(input())
a = list(filter(lambda x: int(x) % 2 == 1, input().split()))
print('Yes' if len(a) % 2 == 0 else 'No')
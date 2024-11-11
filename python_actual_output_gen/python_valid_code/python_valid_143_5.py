import sys

n = int(input())
a = list(map(int, input().split()))
print('Yes' if a.count(0) <= (1 if n > 1 else 0) else 'No')

import os
import sys

def log(*args, **kwargs):
    if os.environ.get('CODEFR'):
        print(*args, **kwargs)

n = int(input())

a = list(map(int, input().split()))

result = a[0]
for i, a1 in enumerate(a):
    if i > 1:
        result = min(result, a1 // (i))
    if i < n - 1:
        result = min(result, a1 // (n - i - 1))

print(result)
        

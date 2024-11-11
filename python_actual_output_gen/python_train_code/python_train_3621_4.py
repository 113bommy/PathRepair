#import sys
#read = lambda: list(map(int, sys.stdin.readline().strip().split()))

n, m, p = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for i in range(n):
    if a[i]%p != 0:
        break
for j in range(m):
    if b[i]%p != 0:
        break
print(i+j)









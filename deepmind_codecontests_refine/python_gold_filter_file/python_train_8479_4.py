import sys
n, k = map(int, input().split())
if k == 1:
    for i in range(1, n+1):
        print(i, end=' ')
    sys.exit();
for i in range(0, k//2):
    print(i+1, n-i, end=' ')
if k%2:
    z = k//2+3
    for i in range(n-k//2, k//2+2, -1):
        z = i
        print(i, end=' ')
    print(z-2, z-1)
else:
    for i in range(n-k//2, k//2, -1):
        print(i, end=' ')


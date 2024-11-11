import sys
n, k, q = map(int, sys.stdin.readline().split())
check = [0]*200012
for i in range(n):
    l, r = map(int,sys.stdin.readline().split())
    check[l] = 1
    check[r+1] = -1
for i in range(1,200001):
    check[i+1] += check[i]
    if check[i] >= k:
        check[i] = 1
    else:
        check[i] = 0
for i in range(1,200000):
    check[i+1] += check[i]

for i in range(q):
    count = 0
    a, b = map(int, sys.stdin.readline().split())
    sys.stdout.write(str(check[b] - check[a-1])+"\n")
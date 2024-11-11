n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
passed = 0
start = 0

for i in range(m):
    if b[i] > a[start] + passed:
        passed += a[start]
        start += 1
    print(start + 1, b[i] - passed)
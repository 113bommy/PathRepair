n, a, b = map(int, input().split())
ar = list(map(int, input().split()))
ar.sort()
if ar[a - 1] == ar[a]:
    print(0)
else:
    print(ar[a] - ar[a - 1])
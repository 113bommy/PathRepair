tc = int(input())
for _ in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    print(*arr[::-1])
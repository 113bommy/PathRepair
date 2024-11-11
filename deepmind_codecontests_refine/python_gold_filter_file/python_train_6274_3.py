t = int(input())
for _ in range(t):
    n = int(input())
    nums = [int(i) for i in input().split()]
    print(*nums[::-1])
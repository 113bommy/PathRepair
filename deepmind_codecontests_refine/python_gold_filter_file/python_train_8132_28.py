n = int(input())
for x in range(n):
    a, b = map(int, input().split())
    print(b + 9 * (a - 1))

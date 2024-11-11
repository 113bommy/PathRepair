n = int(input())
for i in range(n):
    k, q = map(int, input().split())
    print(q + 9 * (k - 1))
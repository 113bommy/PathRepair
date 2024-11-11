n = int(input())
for i in range(n):
    q, k = map(int, input().split())
    print(q + 9 * (k - 1))
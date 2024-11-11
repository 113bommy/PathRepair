t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    print(k-(n-1)*9)
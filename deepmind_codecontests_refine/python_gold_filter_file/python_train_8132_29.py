n = int(input())
for i in range(n):
    k, l = map(int, input().split())
    print((k - 1) * 9 + l)
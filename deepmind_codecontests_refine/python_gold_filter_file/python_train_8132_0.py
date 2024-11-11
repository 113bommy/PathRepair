n = int(input())
for _ in range(n):
    k, x = map(int, input().split())
    print(x+k*9-9)

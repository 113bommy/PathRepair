N = int(input())
for _ in range(N):
    a, b = map(int, input().split())
    print(a * (len(str(b+1)) - 1))
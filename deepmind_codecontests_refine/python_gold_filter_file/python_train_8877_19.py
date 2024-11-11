c = int(input())
for t in range(c):
    a, b, c, d = map(int, input().split())
    print(max(a+b, c+d))

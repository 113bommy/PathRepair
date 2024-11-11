q = int(input())
for i in range(q):
    a, b, c = map(int, input().split())
    x = a + b + c
    print(int(x / 2))
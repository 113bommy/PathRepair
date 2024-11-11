po = int(input())

for _ in range(po):
    a, b, c, d = map(int, input().split())
    x = a + b + c + d
    print(["NO", "YES"][x % 3 == 0 and a <= x and b <= x and c <= x])
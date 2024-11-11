s = int(input())
a, b, c = map(int, input().split())
sum = a + b + c
if a + b + c:
    print(a * s / sum, b * s / sum, c * s / sum)
else:
    print(0, s, 0)
t = int(input())

while t:
    a, b = map(int, input().split())
    print(a * len(str(b + 1)) - 1)
    t -= 1
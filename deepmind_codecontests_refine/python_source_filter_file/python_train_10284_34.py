k = int(input())
a, b = map(int, input().split())

if k - 1 <= b - a:
    print("OK")
else:
    print("NG")
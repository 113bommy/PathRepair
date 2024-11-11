K = int(input())
A, B = map(int, input().split())

if B - A >= 7:
    print("OK")
else:
    print("NG")
k = int(input())
a, b = map(int,input().split())

if b//k - a//k > 0:
    print("OK")
else:
    print("NG")
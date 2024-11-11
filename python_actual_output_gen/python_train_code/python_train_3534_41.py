K = int(input())
A, B = map(int, input().split())

if A//K - (B-1)//K:
    print("OK")
else:
    print("NG")

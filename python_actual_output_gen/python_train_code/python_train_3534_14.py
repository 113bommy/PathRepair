K = int(input())
A, B = map(int, input().split())
if A - B > K -1:
    print("OK")
else:
    print("NG")
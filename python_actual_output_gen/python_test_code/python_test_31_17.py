m, d = map(int, input().split())
thirty = [4, 9, 11]
if m in thirty:
    print(6 if d == 7 else 5)
elif m != 2:
    print(6 if d > 5 else 5)
else:
    print(5 if d > 1 else 4)

# CodeForcesian
# ♥
# اگه میتونی تصور کنی پس حتما میتونی انجامش بدی

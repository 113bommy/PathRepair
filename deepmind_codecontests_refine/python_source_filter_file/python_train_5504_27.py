N = int(input())
import re
for _ in [0]*N:
    a = input().zfill(100)
    b = input().zfill(100)
    result = []
    prev = 0
    for i in range(1, 81):
        n = int(a[-i]) + int(b[-i]) + prev
        result.append(n%10)
        prev = n // 10
    if prev > 0 or int(a[:21]) + int(b[:21]) > 0:
        print("overflow")
    else:
        result = "".join(map(str, result[::-1]))
        print(int(result))
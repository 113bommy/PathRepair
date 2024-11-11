import math
for _ in range(1):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    arr = list(map(str , arr))
    " ".join(arr)
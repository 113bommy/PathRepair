import sys
import math

input = sys.stdin.readline

def algo(n, arr):
    mx = max(arr)

    ans = -1

    for i in range(n):
        if arr[i] == mx:
            if i-1 >= 0 and arr[i-1] != mx:
                ans = i + 1
                break
            if i+1 < n and arr[i+1] != mx:
                ans = i + 1
                break
    return ans
        

for _ in range(int(input())):
    n = int(input().strip())

    arr = list(map(int, input().split()))

    res = algo(n, arr)
    print(res)
    

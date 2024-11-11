import math

def election(arr):
    return max(math.ceil(2*sum(arr) / len(arr)), max(arr))

n = int(input())
arr = list(map(int, input().split()))
print(election(arr))
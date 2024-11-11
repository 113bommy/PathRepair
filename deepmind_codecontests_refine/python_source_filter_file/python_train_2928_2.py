from functools import lru_cache

n, k, x = map(int, input().split())

arr = list(map(int, input().split()))

@lru_cache(maxsize=50000)
def dp(i,y):
    if i==0 and y==0:
        return 0
    elif i < 0 or y<= 0:
        return -1000000000001
    return max(dp(i-delta-1, y-1) + arr[i-delta-1] for delta in range(min(k,i+1)))

print(max(dp(n,x),-1))

N, K = map(int, input().split())
A = list(map(int, input().split()))

def f(x):
    return sum((a+x-1)//x - 1 for a in A)

l = 0
r = 10**9+1 
while r - l > 1:
    mid = (l + r) // 2
    if f(mid) <= K:
        r = mid
    else:
        l = mid
print(r)
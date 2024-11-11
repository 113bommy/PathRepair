import sys
input = sys.stdin.readline

N, K = map(int, input().split())

def search(odd_num):
    c = 0
    upper = odd_num
    down = odd_num
    while upper <= N:
        c += (upper-down+1)
        upper = 2*upper+1
        down = 2*down
    if down <= N:
        c += (N-down+1)
    return c

def binary_search(maximum, odd):
    l = 0
    r = maximum+2
    while r-l > 1:
        m = (r+l)//2
        num = 2*m+1 if odd else 2*m
        if odd:
            count = search(num)
        else:
            count = search(num//2) - 1
        if count >= K:
            l = m
        else:
            r = m
    return 2*l+1 if odd else 2*l

a1 = binary_search((N+1)//2, odd=True)
a2 = binary_search((N+1)//2, odd=False)

print(max(a1, a2))
n, k = map(int, input().split())

L = 0
R = (2**n) - 1
while L <= R:
    mid = -1*(-(L+R)//2)
    if mid == k:
        print(n)
        break
    elif mid > k:
        R = mid-1
    else:
        L = mid+1
    n -= 1
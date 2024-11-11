n, p = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
left = 0
right = 10**9+1
while right - left > 1:

    mid = left + (right - left)//2
    x = mid

    flag = 1
    for i in range(n):
        if a[i] <= x:
            x += 1
        else:
            flag = 0
            break

    if flag:
        right = mid
    else:
        left = mid

ansleft = right

left = 0
right = 10**9+1

while right - left > 1:
    mid = left + (right - left)//2
    x = mid

    flag = 1
    r = 0
    for i in range(n):
        while r < n:
            if a[r] <= x:
                r += 1
            else:
                break

        if r - i >= p:
            flag = 0
            break
        x += 1

    if flag:
        left = mid
    else:
        right = mid

ansright = left

ans = [i for i in range(ansleft, ansright+1)]
print(len(ans))
print(*ans)

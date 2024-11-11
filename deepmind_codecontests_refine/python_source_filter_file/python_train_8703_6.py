l, r, x, y, k = list(map(int, input().split()))
answer = 'NO'
while x<y:
    mid = (x+y)//2
    res = mid*k
    if l <= res <= r:
        answer = 'YES'
        break
    elif res > r:
        y = mid - 1
    else:
        x = mid + 1
print(answer)
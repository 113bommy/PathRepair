t = int(input())
for _ in range(t):   
    nn, x, y = map(int, input().split())
    if nn == 2:
        print(x, y)
        continue
    n = nn
    diff = y-x
    prime = True
    maxdivisor = 1
    for i in range(min(diff//2, n), 1, -1):
        if diff%i==0:
            prime = False
            if i > (n-1):
                continue
            else:
                maxdivisor = i
                break
    if n > diff:
        inc = 1
    elif prime:
        inc = diff
    else:
        inc = diff//maxdivisor
    mid = diff // inc
    n-=(mid+1)
    start = x - (min(x//inc if x%inc!=0 else (x//inc)-1, n)*inc)
    ans = [start+(inc*i) for i in range(nn)]
    print(*ans)
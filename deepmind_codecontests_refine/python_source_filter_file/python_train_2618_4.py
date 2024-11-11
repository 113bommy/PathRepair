n, m = map(int, input().split())

if m%n==0 and m>=n:
    mov = 0
    m = m//n
    while m%2==0:
        mov += 1
        m //= 2
        if m==0:
            break
    while m%3==0:
        mov += 1
        m //= 3
        if m==0:
            break
    if m==0:print(mov)
    else:print(-1)
else:
    print(-1)

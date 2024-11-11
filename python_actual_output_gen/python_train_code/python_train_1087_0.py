n, m = map(int, input().split())

if n > m:
    n, m = m, n

if n == 1:
    ans = m//6+2*max(m%6-3, 0)
    print(ans)

elif n == 2:
    if m == 2:
        print(0)
    elif m == 3:
        print(4)
    elif m == 7:
        print(8)
    else:
        print(n*m)

else:
    ans = ((n*m)//2)*2
    print(ans)

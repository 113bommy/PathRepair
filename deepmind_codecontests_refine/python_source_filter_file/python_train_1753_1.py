k,a,b = map(int, input().split())
inc_two = a - b
if inc_two > 0:
    k -= a
    print(1 +2*(k + inc_two - 1) // inc_two)
else:
    if a >= k:
        print(1)
    else:
        print(-1)
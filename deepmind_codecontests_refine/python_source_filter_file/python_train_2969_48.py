x, s, s = input().split()
x = int(x)
if s == 'week':
    ans = 366 // 7
    if x > 3:
        ans += 1
    print(ans)
else:
    if x > 30:
        print(7)
    elif x > 29:
        print(11)
    else:
        print(12)

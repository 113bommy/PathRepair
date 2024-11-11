n = input().split()
a , b = int(n[0]) , int(n[1])
ans = int(0)
if b%a != 0:
    print(-1)
else:
    now = int(b / a)
    while now%2 == 0 and now>0:
        now /= 2
        ans += 1
    while now%3 == 0 and now>0:
        now /=3
        ans += 1
    if now != 0 :
        print(-1)
    else:
        print(ans)
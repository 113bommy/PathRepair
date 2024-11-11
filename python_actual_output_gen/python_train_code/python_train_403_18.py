n , m = map(int, input().split())
tab = list(map(int, input().split()))

zapisane = 0
index = 0
for i in tab:
        if index == n-1 and zapisane + i >= m:
            print((zapisane + i) // m ,end=' ')
            break


        if zapisane + i <= m:
            zapisane += i
            print(0,end=' ')

        else:
            zapisane + i > m
            zapisane += i
            print(zapisane // m,end=' ')
            zapisane %= m

        index += 1





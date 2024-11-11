t = int(input())
for _ in range(t):
    d = int(input())
    if (d**2)/4 < d:
        print('N')
    elif (d**2)//4 == d:
        print('Y',d/2,d/2)
    else:
        epsilon = 0.00000001
        l = 0
        r = d/2
        while (r-l) > epsilon:
            mid = l + (r-l)/2
            if ((d-mid)*mid) > d:
                r = mid
            else:
                l = mid
        ans = mid
        print('Y',d-mid,mid)
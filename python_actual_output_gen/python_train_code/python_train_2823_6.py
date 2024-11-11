def ans(n,r,a):
    a.insert(0,0)
    p,l,pl,cnt = 0,0,0,0

    for i in range(1,n+1):
        if i == p+r:
            if a[i] == 1:
                cnt+=1
                pl = i
                p = i + r -1
            elif l > pl:
                cnt += 1
                pl = i
                pl = l + r - 1
            else:
                return -1
        if a[i] == 1:
            l = i
    if l == 0:
        return -1
    if n > p:
        if l > n-r:
            cnt += 1
        else:
            return -1
    return cnt


# input data
n,r = map(int,input().split())
a = [int(i) for i in input().split()]

print(ans(n,r,a))

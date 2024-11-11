a = input()
br = True
for i in a:
    if i == 'w' or i == 'm':
        print(0)
        br = False
        break
if br:
    mod = 10**9-7
    n = len(a)
    hk = [0] * (n+1)
    hk[0] = 1
    hk[1] = 1
    for i in range(2,n+1):
        hk[i] = hk[i-1]
        if a[i-1] == a[i-2] and (a[i-1] == 'u' or a[i-1] == 'n'):
            hk[i] += hk[i-2]
            hk[i] %= mod
    print(hk[n])

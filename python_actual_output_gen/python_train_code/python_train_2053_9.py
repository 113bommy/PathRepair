t = int(input())
for _ in range(t):
    n, g, b = map(int, input().split())
    p = (n+1)//2
    q = p//g
    r = p%g
    if r != 0:
        if b*q >= n-p:
            print((g+b)*q+r)
        else:
            print((g+b)*q+r+(n-p)-b*q)
    else:
        if b*(q-1) >= n-p:
            print((g+b)*(q-1)+g)
        else:
            print((g+b)*q+r+(n-p)-b*(q-1))
t = int(input())
for tt in range(t):
    n,k = [int(s) for s in input().split()]
    a = [int(s) for s in input().split()]
    k_tot = 0
    s = 0
    for i in range(n):
        ai_val = 10**a[i]
        ki = k-k_tot+1
        if i < n-1:
            ki = min(ki, 10**(a[i+1]-a[i])-1)
        k_tot += ki
        s += ai_val*ki
        if k_tot >= k:
            break
    print(s)
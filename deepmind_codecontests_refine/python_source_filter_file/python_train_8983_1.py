MOD = 10**9 + 7
t = int(input())
for test in range(t):
    n, k = [int(i) for i in input().split()]
    if k==1:
        print(1)
    elif k==2:
        print(n+1)
    elif n==1:
        print(2)
    else:
        ans = n+1
        v = [1 for i in range(n-1)]
        for my_iter in range(k-2):
            v_new = [0 for i in range(n-1)]
            v_new[-1] = v[0]
            for it in range(1,n-1):
                v_new[-it-1] = (v_new[-it]+ v[it]) % MOD
            #print(v_new)
            ans+= sum(v_new) % MOD
            v = v_new
        print(ans)
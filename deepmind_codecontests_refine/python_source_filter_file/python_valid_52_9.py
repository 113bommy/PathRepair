N = int(input())
for _ in range(N):
    n = int(input())
    lst = list(map(int, input().split()))
    pref_sum = [0]
    for i in range(n):
        pref_sum.append(pref_sum[-1] + lst[i])
    sm = sum(lst)
    mx = -(10**18)
    for i in range(1, n):
        sm1 = pref_sum[i]
        sm2 = sm - sm1
        val1 = sm1 / i
        val2 = sm2 / (n - i)
        mx = max(mx, val1 + val2)
    print(mx)
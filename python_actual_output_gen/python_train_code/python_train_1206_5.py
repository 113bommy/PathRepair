#
# Created by Polusummator on 24.10.2020
# --------- Little PyPy Squad ---------
# Verdict: 
#
n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
if k == 1:
    print(min(a))
elif (k == 2 and a.index(max(a)) in [0, n - 1]) or k >= 3:
    print(max(a))
else:
    a1 = a[::-1]
    pref = [a[0]]
    pref1 = [a1[0]]
    for i in range(1, n):
        pref.append(min(pref[i - 1], a[i]))
        pref1.append(min(pref1[i - 1], a1[i]))
    ans = -10000000000
    for i in range(n - 1):
        ans = max(ans, max(pref[i], pref1[n - i - 1]))
    print(ans)
    # print(min(a))

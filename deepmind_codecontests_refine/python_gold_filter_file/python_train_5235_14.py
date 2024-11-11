# http://codeforces.com/contest/1430/problem/B
t = int(input())
for g in range(t):
    (n, k) = map(int, input().split())
    a = sorted([ int(x) for x in input().split() ], reverse=True)
    uusa = a[1:min(n-1, k)+1]
    #print("assda", uusa)
    maks = a[0] + sum(uusa)
    print(maks)



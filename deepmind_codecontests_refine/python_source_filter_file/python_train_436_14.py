def solve(n,ar):
    mn = int(1e9)
    mx = int(-1e9)
    for i in range(n):
        if i > 0 and ar[i] == -1 and ar[i - 1] != -1:
            mn = min(mn, ar[i - 1])
            mx = max(mx, ar[i - 1])
        if i < n - 1 and ar[i] == - 1 and ar[i + 1] != -1:
            mn = min(mn, ar[i + 1])
            mx = max(mx, ar[i + 1])



    k = (mx+mn)//2
    m = 0
    for i in range(n-1):
        if ar[i] == -1:
            ar[i] = k
        if i>0:
            m = max(m,abs(ar[i]-ar[i-1]))

    print(m, k)



if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ar = list(map(int,input().split()))
        solve(n,ar)
import sys
t = int(sys.stdin.readline())
for i in range(t):
    n, m = [int(i) for i in sys.stdin.readline().split()]
    st = 1
    if(n == 1):
        if (m == int(1)):
            print("1")
        else:
            print("0")
        st = -1
    ans = n * (n - 1) // 2 + n
    nl = n - m
    if (n - m) % (m + 1) == 0:
        g = (n - m) // (m + 1)
        ans -= (g * (g - 1) // 2 + g) * (m + 1)
    else:
        g = (n - m) // (m + 1) + 1
        ans -= (g * (g - 1) // 2 + g) * ((n - m) % (m + 1))
        g -= 1
        ans -= (g * (g - 1) // 2 + g) * ((n - m - 1) - (n - m) % (m + 1))
    if st == 1:
        print(ans)

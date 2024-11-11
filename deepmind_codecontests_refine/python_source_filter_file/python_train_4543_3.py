mod = 1e9 + 7
a = input()
n, m, k = map(int, a.split())
if k == -1 and ((n+m) & 1) == 1:
    print(0)
else:
    print(pow(2, (n-1) * (m-1)), mod)
t = int(input())
for _ in range(t):
    n, k = [int(i) for i in input().split()]
    s = [int(i) for i in input().split()]
    m = n - 2*k - 1
    _s = s[m:]
    mat = []
    mx = -10**9
    if m >= 0:
        for i in range(2*k+1):
            for j in range(i+1, 2*k+1):
                val = (m+i+1)*(m+j+1)-k*(_s[i]|_s[j])
                if val > mx:
                    mx = val
        print(mx)

    else:
        _mx = -10**9
        for i in range(n):
            for j in range(i+1, n):
                val = i*j + i + j + 1 - k*(s[i]|s[j])
                if val > _mx:
                    _mx = val
        print(_mx)

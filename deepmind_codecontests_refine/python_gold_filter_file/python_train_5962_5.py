import math
t = int(input())
for _ in range(t):
    m, d, w = map(int, input().split())
    if d == 1:
        print(0)
        continue
    g = w // math.gcd(d - 1, w)
    # if g == 1:
    #     print(m * d - 1)
    #     continue
    m, d = min(m, d), max(m, d)
    
    x, r = m // g, m % g
    # print('a', g, x, r)
    res = (x - 1 + 1) * (x - 1) * g // 2 + r * x 

    print(res)
test = int(input())

for k in range(test):
    n, x, t = list(map(int, input().split()))
    d = t // x
    m = min(n, d)
    print(n * d - m * (m+1) // 2)

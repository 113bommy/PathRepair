t = int(input())

for _ in range(t):
    a, K = list(map(int, input().split()))
    for i in range(2, K + 1):
        sa = str(a)
        mn = min(map(int, sa))
        mx = max(map(int, sa))
        if mn == 0:
            a += (K - i) * a
            break
        else:
            a = a + mx * mx
        
    print(a)
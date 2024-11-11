N = int(input())
a = list(map(int, input().split()))
if max(a) - min(a) >= 2:
    print("No")
    exit()
else:
    M = max(a)
    m = min(a)
    if M == m:
        if m <= N / 2 or m == N - 1:
            print("Yes")
        else:
            print("No")
    else:
        if a.count(m) >= M or a.count(M) < 2 * a.count(m):
            print("No")
        else:
            print("Yes")
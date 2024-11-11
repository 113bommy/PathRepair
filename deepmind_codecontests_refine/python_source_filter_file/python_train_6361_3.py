import sys, random


n, k = list(map(int, input().split()))
l = 1
r = n
b = True
while b:
    while r - l > k * 4 + 1:
        m = (l + r) // 2
        print(l, m)
        sys.stdout.flush()
        #ans = "Yes" if random.randint(1, 2) == 1 else "No"
        ans = input()
        if ans == "Bad":
            sys.exit(0)
        if ans == "Yes":
            r = min(n, m + k)
            l = max(0, l - k)
        else:
            r = min(n, r + k)
            l = max(1, m - k)
    rnd = random.randint(l, r)
    print(rnd, rnd)
    sys.stdout.flush()
    ans = input()
    if ans == "Bad":
        sys.exit(0)
    if ans == "Yes":
        sys.exit(0)
    else:
        r = min(n, r + k)
        l = max(1, l - k)
t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    kek = set()
    for j in range(2 * n):
        kek.add((j + arr[j % n]) % n)
    if len(kek) != 2 * n:
        print("NO")
    else:
        print("YES")
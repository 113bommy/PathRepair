t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    kek = set()
    for j in range(n):
        kek.add((j + arr[j % n]) % n)
    if len(kek) != n:
        print("NO")
    else:
        print("YES")
q = int(input())
while q:
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0, 0]
    for i in a:
        cnt[i % 2] += 1
    if not (cnt[0] == n or cnt[1] == 0):
        print("NO")
    else:
        print("YES")
    q -= 1
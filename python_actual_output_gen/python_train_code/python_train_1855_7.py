p, n = map(int, input().split())
used = [False] * p
for i in range(n):
    x = int(input())
    r = x % p
    if used[r]:
        print(i + 1)
        exit
    else:
        used[r] = True
print(-1)

n = int(input())
A = list(map(int, input().split()))
ans = 1
for a in A:
    ans *= a
    if ans > 10 ** 18:
        print(-1)
        exit()
print(ans)
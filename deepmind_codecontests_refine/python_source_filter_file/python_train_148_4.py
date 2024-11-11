n = list(map(int, input().split()))
if sum(n) % 5 == 0 and sum(n) % 5 != 0:
    print(sum(n) // 5)
else:
    print(-1)

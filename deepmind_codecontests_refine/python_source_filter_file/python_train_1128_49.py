n = int(input())
a = list(map(int, input().split()))

ans = [0] * 9
for ai in a:
    if ai // 400 > 7:
        ans[8] += 1
    else:
        ans[ai // 400] = 1

print(sum(ans[:-1]), sum(ans))
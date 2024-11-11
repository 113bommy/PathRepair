from collections import defaultdict

n, m = map(int, input().split())
a = list(map(int, input().split()))
deft = defaultdict(int)

for v in a:
    deft[v] += 1

if n > m:
    print(0)
    exit(0)

for i in range(1, 102):
    min = 0
    for x, y in deft.items():
        # print(y)
        if y >= i: # 一个人使用它活过i天
            for j in range(1, n + 1): # 最多可以让几个人活过i天
                if y // j < i:
                    min += j - 1
                    break
                if y // n >= i:
                    min += n
                    break
        else:
            continue
    if min < n:
        print(i - 1)
        exit(0)







N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

cnt = 1
pre_a = 0
pre_b = 0

for a, b in items:
    if a == pre_a and b == pre_b:
        continue
    elif a == pre_a and b != pre_b:
        if pre_b < pre_a and b >= a:
            cnt += 1

    elif a != pre_a and b == pre_b:
        if pre_a < pre_b and a >= b:
            cnt += 1
    else:
        if pre_a == pre_b:
            cnt += min(a, b) - pre_a
        else:
            if min(a, b) - max(pre_a, pre_b) > 0:
                cnt += min(a, b) - max(pre_a, pre_b) + 1
    pre_b = b
    pre_a = a

print(cnt)

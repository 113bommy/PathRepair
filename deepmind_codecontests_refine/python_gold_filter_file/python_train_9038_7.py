n, k = [int(x) for x in input().split()]

flowers = []

for _ in range(n):
    tmp = [int(x) for x in input().split()]
    flowers.append(tmp)

def aaa(p, l):
    count = 0
    for x in l:
        w, d = x[0], x[1]
        if p - w < 0:
            pass
        else:
            count += (p - w) // d + 1
    return count

flag = True
left, right = 1, 10 ** 19
ans = 0

while flag:
    point = (right + left) // 2
    if point == left:
        flag = False
        if aaa(left, flowers) >= k:
            ans = left
        else:
            ans = right
    else:
        if aaa(point, flowers) < k:
            left = point
        else:
            right = point

print(ans)

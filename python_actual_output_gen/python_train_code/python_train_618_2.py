n = int(input())
x = [int(y) for y in input().split()]
ans = []
for i in x:
    a = 0
    b = 0
    j = i
    while j % 2 == 0:
        j /= 2
        a += 1
    while j % 3 == 0:
        j /= 3
        b += 1
    ans.append([-b, a, i])
ans.sort()
for z in ans:
    print(z[2], end=' ')
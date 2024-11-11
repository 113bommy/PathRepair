n = int(input())
a = set()
for i in range(2, 3000):
    for j in range(2, i):
        if (i % j == 0):
            break
    else:
        a.add(i)
ans = 0
for i in range(2, n+1):
    tmp = 0
    for j in range(2, n+1):
        if (i % j == 0):
            if (j in a):
                tmp += 1
    if (tmp % 2 == 0):
#         print(i)
        ans += 1
        tmp = 0
print(ans)
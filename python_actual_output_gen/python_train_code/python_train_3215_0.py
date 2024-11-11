x, d = [int(i) for i in input().split()]
cr = 0
ans = []
while x:
    i = 0
    while ((1 << i) - 1) <= x:
        i += 1
    for j in range(i - 1):
        ans.append(cr)
    x -= (1 << (i - 1)) - 1
    cr += d 
print(len(ans))
print(*ans)

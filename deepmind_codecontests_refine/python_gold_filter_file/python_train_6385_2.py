n = int(input())
l = []
for i in range(n):
    m = list(map(int, input()))
    l.append(m)

ans = 0
for i in range(len(l[0])):
    pre = 1
    for j in range(0, n-1):
        if l[j][i] == l[j+1][i]:
            pre += 1

        else:
            break

    if n == pre:
        ans += 1
    else:
        break
print(ans)

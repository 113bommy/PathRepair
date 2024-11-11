##def count(x):
##    p = []
##    while x > 0:
##        p.append(x % 10)
##        x //= 10
##    p += [0] * (n - len(p))
##    p.reverse()
##    ans = [0] * n
##    k = 1
##    for i in range(1, n):
##        if p[i] == p[i - 1]:
##            k += 1
##        else:
##            ans[k - 1] += 1
##            k = 1
##    ans[k - 1] += 1
##    return ans
##
##
##n = int(input())
##gans = [0] * n
##for i in range(10 ** n):
##    ans = count(i)
##    for j in range(n):
##        gans[j] += ans[j]
##print(*gans)
n = int(input())
q = 998244353
ans = [0] * n
for i in range(1, n):
    ansi = 9 * pow(10, n - i - 1, q) * 2 % q
    if n - i - 2 >= 0:
        ansi += (9 * 9 * pow(10, n - i - 2, q) % q) * (n - i - 1) % q
    ans[i - 1] = int(ansi) * 10 % q
ans[-1] = 10
print(*ans)
















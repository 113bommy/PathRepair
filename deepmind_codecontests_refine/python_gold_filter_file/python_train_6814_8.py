a = int(input())
sm = 30 * 45 * 10**30 // 10 + 1
l = 1
r = 10 ** 30
l += a - sm % a
r += a - sm % a
print(l,r)
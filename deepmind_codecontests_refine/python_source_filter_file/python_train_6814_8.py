a = int(input())
sm = 15 * 45 * 10**15 // 10 + 1
l = 1
r = 10 ** 15
l += a - sm % a
r += a - sm % a
print(l,r)
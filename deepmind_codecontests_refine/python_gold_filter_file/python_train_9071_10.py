# M = 10 ** 9 + 7
# def fexp(n):
#     ret = 1
#     a = 4
#     while n:
#         if n & 1:
#             ret = (ret * a) % M
#         a = (a * a) % M
#         n >>= 1
#     return ret
#
# def func(n):
#     ret = ((fexp(n) - 1) // 3 + M) % M
#     # print(n, fexp(n), ret)
#     maxn = ret * 2 - 1
#     res = ((maxn + 1) * ret // 2) % M
#     # print(res)
#     return res
#
# def func2(n):
#     ret = (2 * (fexp(n) - 1) // 3 + M) % M
#     print(n, ret)
#     maxn = ret * 2
#     res = ((maxn + 2) * ret // 2) % M
#     print(res)
#     return res
#
# l, r = map(int, input().split())
# l = l - 1
# a1, a2 = 0, 0
# if l == 0:
#     a1 = 0
# else:
#     n1 = int(l // 2) + (l % 2)
#     n2 = int(l // 2)
#     odd = func(n1)
#     even = func2(n2)
#     a1 = odd + even
#     print(odd, even, a1)
# n1 = int(r // 2) + (r % 2)
# n2 = int(r // 2)
# odd = func(n1)
# even = func2(n2)
# a2 = odd + even
# ans = int((a2 - a1 + M) % M)
# print(odd, even, a2)
# print(ans)
l, r = map(int, input().split())
ans = 0
M = 10 ** 9 + 7
def func(n):
    a = 0
    odd = 1
    even = 2
    s = 0
    ret = 0
    while True:
        p = 2 ** a
        flag = False
        if s + p >= n:
            t = n - s
            flag = True
        else:
            t = p
        t = int(t % M)
        # print(t)
        if a % 2 == 0:
            ret = (ret + (odd + odd + (t - 1) * 2) // 2 * t) % M
            odd += p * 2
        else:
            ret = (ret + (even + even + (t - 1) * 2) // 2 * t) % M
            even += p * 2
        # print(n, ret)
        if flag:
            break
        a += 1
        s += p
    return ret
ans = (func(r) - func(l - 1) + M) % M
ans = int(ans)
print(ans)

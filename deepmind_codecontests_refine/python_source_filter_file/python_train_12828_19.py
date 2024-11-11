# for t in range(int(input())):
#     s = input()
#     i, j = 0, 0
#     cnt = 0
#     ans = float('inf')
#     dic = {}
#     while j < len(s):
#         if len(dic) < 3:
#             dic[s[j]] = dic.get(s[j], 0) + 1
#         # print(j)
#         # print(dic)
#         while len(dic) == 3:
#             ans = min(ans, j - i + 1)
#             dic[s[i]] -= 1
#             if dic[s[i]] == 0:
#                 del dic[s[i]]
#             i += 1
#
#         j += 1
#     print((0, ans)[ans < float('inf')])


# for t in range(int(input())):
#     n = int(input())
#     s = list(map(int, input().split()))
#     dp = [1] * n
#     for i in range(n):
#         k = 2
#         while (i + 1) * k <= n:
#             j = (i + 1) * k
#             if s[i] < s[j - 1]:
#                 dp[j - 1] = max(dp[j - 1], dp[i] + 1)
#             k += 1
#     print(max(dp))


# for T in range(int(input())):
#     t = input()
#     z, o = 0, 0
#     for ch in t:
#         z = z + 1 if ch == '0' else z
#         o = o + 1 if ch == '1' else o
#     if z > 0 and o > 0:
#         print('01' * len(t))
#     elif o > 0 and not z:
#         print('1' * len(t))
#     else:
#         print('0' * len(t))


# for t in range(int(input())):
#     n = int(input())
#     a = list(map(int, input().split()))
#     a.sort()
#     ans = []
#     while a:
#         ans.append(str(a.pop(len(a) // 2)))
#     print(' '.join(ans))


# for t in range(int(input())):
#     n = int(input())
#     a = list(map(int, input().split()))
#     cnt = 0
#     p = set()
#     l, r = 0, sum(a)
#     left, right = {}, {}
#     for i in a:
#         right[i] = right.get(i, 0) + 1
#     for i in range(n - 1):
#         l += a[i]
#         left[a[i]] = left.get(a[i], 0) + 1
#         r -= a[i]
#         right[a[i]] = right.get(a[i], 0) - 1
#         if not right[a[i]]:
#             del right[a[i]]
#         j = n - i - 1
#         if (2 + i) * (i + 1) // 2 == l and (j + 1) * j // 2 == r:
#             if len(left) == i + 1 and len(right) == j:
#                 cnt += 1
#                 p.add((i + 1, n - i - 1))
#     print(cnt)
#     if cnt:
#         for el in p:
#             print(*el)


# for t in range(int(input())):
#     n = int(input())
#     G = []
#     taken = [False] * n
#     girl = -1
#     for i in range(n):
#         g = list(map(int, input().split()))
#         k = g[0]
#         single = True
#         for j in range(1, k + 1):
#             if not taken[g[j] - 1]:
#                 taken[g[j] - 1] = True
#                 single = False
#                 break
#         if single:
#             girl = i
#     if girl == -1:
#         print('OPTIMAL')
#     else:
#         print('IMPROVE')
#         print(girl + 1, taken.index(False) + 1)


# for t in range(int(input())):
#     n = int(input())
#     a = list(map(int, input().split()))
#     odd, even = [], []
#     for i in range(2 * n):
#         if a[i] % 2:
#             odd.append(i + 1)
#         else:
#             even.append(i + 1)
#     for i in range(n - 1):
#         if len(odd) >= len(even):
#             print(odd.pop(), odd.pop())
#         else:
#             print(even.pop(), even.pop())


# for t in range(int(input())):
#     n = int(input())
#     a = list(map(int, input().split()))
#     a.sort()
#     ans, i, j = 0, 0, 1
#     while j < n:
#         if a[i] < a[j]:
#             ans += 1
#             i += 1
#             j += 1
#         else:
#             while j < n and a[i] == a[j]:
#                 i += 1
#                 j += 1
#     print(ans + 1)


# for t in range(int(input())):
#     n = int(input())
#     a = list(map(int, input().split()))
#     got = False
#
#     b = 1
#     while not got and b < 2 * n - 1:
#         if b % 2:
#             i, j = (b - 1) // 2, (b + 1) // 2
#         else:
#             i, j = b // 2 - 1, b // 2 + 1
#         left, right = set(a[:i]), set(a[j:])
#         if left & right:
#             got = True
#         b += 1
#     print('YES' if got else 'NO')


# n, m, k = list(map(int, input().split()))
# A = list(map(int, input().split()))
# B = list(map(int, input().split()))
# ans = 0
# a, b = [0], [0]
# for el in A:
#     a.append(a[-1] + el)
# for el in B:
#     b.append(b[-1] + el)
# d = [(i, k//i) for i in range(1, int(k**0.5)+1) if k % i == 0]
# d += [(j, i) for i, j in d if i != j]
# for i in range(n):
#     for j in range(m):
#         for q, p in d:
#             if i + q <= n and j + p <= m:
#                 if a[i + q] - a[i] == q and b[j + p] - b[j] == p:
#                     ans += 1
# print(ans)


# for t in range(int(input())):
#     n = int(input())
#     s = input()
#     dic, se = {s: 1}, {s}
#     for k in range(2, n):
#         p = s[k - 1:] + (s[:k - 1], s[:k - 1][::-1])[(n % 2) == (k % 2)]
#         # print(k, p)
#         if p not in dic:
#             # print(dic, p)
#             dic[p] = k
#             se.add(p)
#     if s[::-1] not in dic:
#         dic[s[::-1]] = n
#         se.add(s[::-1])
#     # print(dic)
#     ans = min(se)
#     print(ans)
#     print(dic[ans])


# for t in range(int(input())):
#     a, b, p = list(map(int, input().split()))
#     s = input()
#     road = [a if s[0] == 'A' else b]
#     st = [0]
#     for i in range(1, len(s) - 1):
#         if s[i] != s[i - 1]:
#             road.append(road[-1] + (a, b)[s[i] == 'B'])
#             st.append(i)
#     # print(road)
#     pay = road[-1]
#     j = 0
#     while pay > p and j < len(st):
#         pay = road[-1] - road[j]
#         j += 1
#     # print(j)
#     print(st[j] + 1 if j < len(st) else len(s))


for t in range(int(input())):
    n, x, y = list(map(int, input().split()))
    print(max(x + y - n + 1, 1), min(n, x + y - 1))

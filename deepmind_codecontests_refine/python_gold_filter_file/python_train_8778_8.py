n, m = map(int, input().split())
a = [[int(j) for j in input().split()] for i in range(m)]
a.sort(key=lambda x: x[1], reverse=True)
c = 0
for k, v in a:
    if n >= k:
        c += k*v
        n -= k
        if n == 0:
            print(c)
            exit()
    else:
        c += n*v
        print(c)
        exit()
print(c)












# con = {}
# c = 0
# for i in range(m):
#     x, y = map(int, input().split())
#     con[y] = x
# #d = dict(sorted(con.items(), key=lambda kv: kv[1], reverse=True))
# d = dict(sorted(con.items(), reverse=True))
#
# for v, k in d.items():
#     for i in range(k):
#         c += v
#         n -= 1
#         if n == 0:
#             print(c)
#             exit()

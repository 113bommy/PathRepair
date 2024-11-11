#
# def freedge(milk, h):
#     freed = [[0, 0] for _ in range(h)]
#     j = 1
#     while milk:
#         m = max(milk)
#         if freed[-j][0] == 0:
#             if h+1-j - m < 0:
#                 return False
#             for i in range(j,j+m):
#                 freed[-i][0] = 1
#             milk.remove(m)
#             a = m+j
#             continue
#         if freed[-j][1] == 0:
#             if h+1-j - m < 0:
#                 return False
#             for i in range(j,j+m):
#                 freed[-i][1] = 1
#             b = m+j
#             milk.remove(m)
#             continue
#
#         j = max(a, b)
#         if j > h:
#             return False
#
#     return True

def check(parts, h):
    parts = sorted(parts, reverse=True)
    while parts:
        m = parts[0]
        h -= m
        if h < 0:
            return False
        parts = parts[1:]
        if parts:
            parts = parts[1:]
        else:
            return True
def find_max(n,h, milk):
    for k in range(2,len(milk)):
        if check(milk[:k], h) == False:
            return k-1
    return n
n, h = map(int, input().split())
milk = list(map(int, input().split()))
print(find_max(n, h, milk))
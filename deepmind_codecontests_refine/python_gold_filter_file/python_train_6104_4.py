import sys
sys.setrecursionlimit(100000000)
# def input(): return sys.stdin.readline()[:-1]
def iin(): return int(input())
def impin(): return map(int, input().split())
def irrin(): return [int(x) for x in input().split()]
def imrin(n): return [int(input()) for _ in range(n)]

# crr = [0]
# def get(i, k):
#     crr[0] += 1
#     print(crr[0], i, k)
#     if i==0:
#         if 75<k:
#             return '.', 75
#         return f0[k-1], 0
#     if k<=34:
#         return p0[k-1], 0
#     k -= 34
#     s = get(i-1, k)
#     if s[1]==0:
#         return s
#     k -= s[1]
#     if k<=32:
#         return p1[k-1], 0
#     k -= 32
#     if k<=s[1]:
#         return get(i-1, k)
#     k -= s[1]
#     if k<=2:
#         return p2[k-1], 0
#     k -= 2
#     return '.', s[1]*2+68

    #
    # if k<=34+frr[i-1]:
    #     return get(i-1, k-34)
    # if k<=66+frr[i-1]:
    #     return p1[k-34-frr[i-1]-1]
    # if k<=66+2*frr[i-1]:
    #     return get(i-1, k-66-frr[i-1])
    # if k<=68+2*frr[i-1]:
    #     return p2[k-66-2*frr[i-1]-1]
    # return '.'


def get(i, k):
    if i==0:
        if k<=75:
            return f0[k]
        return '.'
    if k <= 34*i:
        return p0[(k-1)%34+1]
    f = 75
    for p in range(i):
        d = k - 34*(i-p)
        if d <= f:
            return get(p, d)
        d -= f
        if d <= 32:
            return p1[d]
        d -= 32
        if d <= f:
            return get(p, d)
        d -= f
        if d <= 2:
            return p2[d]
        f = 68+2*f
    return '.'

    # if k <= 34*i+75:
    #     return f0[k-34*i-75]
    # return get(i-d, k-d*34)


f0 = ".What are you doing at the end of the world? Are you busy? Will you save us?"
p0 = '.What are you doing while sending "'
p1 = '."? Are you busy? Will you send "'
p2 = '."?'
frr = [75]
# for i in range(10**5):
#     frr.append(frr[i]*2+68)
# print(frr[100])
q = iin()
rrr = []
for _ in range(q):
    n, k = impin()
    rrr.append(get(n, k))
print(''.join(rrr))
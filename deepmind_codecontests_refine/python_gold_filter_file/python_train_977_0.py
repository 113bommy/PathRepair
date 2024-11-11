import sys; sys.setrecursionlimit(1000000)

def solve():
    # 3 1 2 4
    # 1 2 3 4

    # 2 1 3 5 4
    # 1 2 3 4 5

    n, = rv()
    a, = rl(1)



    # 3 1 2 7 4 6 5
    # [ , 1 ,  , , , ]
    # [ , 1 , 2 , , , ]
    # [ , 1 , 2 , 4, 5, ]

    mem = [10000000] * (n + 1)
    mem[0] = a[0]
    for i in range(1, n):
        left, right = 0, n - 1
        while left < right:
            mid = (left + right) // 2
            if a[i] < mem[mid]: right = mid
            else: left = mid + 1
        mem[left] = a[i]
        # for j in range(n):
        #     if a[i] < mem[j]:
        #         mem[j] = a[i]
        #         break
    res = 0
    # print(mem)
    for i in range(1, n):
        if mem[i] != 10000000: res = i
    print(res + 1)




def rv(): return map(int, input().split())
def rl(n): return [list(map(int, input().split())) for _ in range(n)]
if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
solve()



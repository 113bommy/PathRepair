import sys
# n -> 1 + (n-1)*(n-2)/2
# 3 -> 2
# 4 -> 4
# 5 -> 7
def solve():
    n, m, v = map(int, input().split())
    if m < n - 1 or m > (n -1)*(n-2) //2:
        print(-1)
        return
    additional = m - (n - 1)
    special = (1 if v != 1 else 2)
    print(special, v)
    for x in range(1, n + 1):
        if x != special and x != v:
            print(v, x)
    for start in range(1, n + 1):
        for other in range(start + 1, n + 1):
            if additional == 0: break
            if start != special and other != special and start != v and other != v:
                print(start, other)
                additional -= 1





if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
solve()
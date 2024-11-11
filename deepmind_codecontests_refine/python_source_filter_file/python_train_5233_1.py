T = int(input())


def solve():
    if r > 2*l:
        ans = "-1 -1"
    else:
        ans = str(l) + " " + str(2*l)
    return ans


for test in range(T):
    l,r = map(int,input().split())
    print(solve())
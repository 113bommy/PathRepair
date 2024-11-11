import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def no():
    print("No")
    exit()

def main():
    def ok(dir):
        goal = abs(xy[dir])
        over=total[dir]-goal
        if over<0 or over%2:
            return False
        if over==0:
            return True
        over//=2
        dp = [False] * (over + 1)
        dp[0] = True
        for d in dd[dir]:
            for i in range(d, goal + 1):
                dp[i] |= dp[i - d]
            if dp[-1]: return True
        return False

    s = input()[:-1]
    xy = list(map(int, input().split()))

    dd = [[], []]
    total=[0,0]
    dir = 0
    cnt = 0
    first = True
    for c in s:
        if c == "F":
            cnt += 1
        if c == "T":
            if first:
                xy[0] -= cnt
                first = False
            else:
                if cnt: dd[dir].append(cnt)
                total[dir]+=cnt
            dir = 1 - dir
            cnt = 0
    if first:
        xy[0] -= cnt
    else:
        if cnt: dd[dir].append(cnt)
        total[dir] += cnt
    #print(xy, dd)

    for dir in range(2):
        if not ok(dir): no()
    print("Yes")

main()

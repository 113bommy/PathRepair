import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
# import random

# N = 10**5
# A = [random.randrange(1,10**9+1) for _ in range(N)]

# import time

def main():
    l = 0
    r = N
    while r-l > 1:
        m = (r+l)//2
        ok = True
        if m == 1:
            pre = -1
            for a in A:
                if pre >= a:
                    ok = False
                    break
                pre = a
        else:
            dp = {}
            needreset = 10**15
            exception = set()
            pre = -1
            for a in A:
                ind = a
                for _ in range(40):
                    # 修正
                    if needreset >= ind or ind in exception:
                        if not ind in dp.keys():
                            dp[ind] = 0 if pre < a else 1
                    else:
                        dp[ind] = 0 if pre < a else 1
                        exception.add(ind)
                    # たす
                    if dp[ind] < m:
                        dp[ind] += 1
                        break
                    elif ind == 1:
                        ok = False
                        break
                    else:
                        # 繰り上がり
                        dp[ind] = 1
                        ind -= 1
                if not ok: break
                # 更新
                if pre > a:
                    needreset = a
                    exception = set()
                pre = a

        if ok:
            r = m
        else:
            l = m

    print(r)


if __name__ == "__main__":
    #dt = time.time()
    main()
    #print(time.time()-dt)
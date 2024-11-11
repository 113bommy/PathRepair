def main():
    from collections import Counter as ct
    from bisect import bisect_left as bl

    n = int(input())
    max_a = sorted(ct(list(map(int, input().split()))).values())
    now_a = [i for i in max_a]
    m = len(max_a)
    cnt = m
    ans = 0
    ans_list = []

    for use in range(n, 0, -1):
        rest = ans
        nex = now_a[0]
        # restの分だけ戻す
        while rest:
            val = nex
            start = bl(now_a, val+1)
            nex += 1
            for i in range(start-1, -1, -1):
                if now_a[i] == max_a[i]:
                    if start != m:
                        nex = now_a[start]
                    break
                elif now_a[i] == 0:
                    cnt += 1
                now_a[i] += 1
                rest -= 1
                if rest == 0:
                    break
        # 大きい方から使っていく
        while True:
            if cnt < use:
                ans_list.append(ans)
                break
            ans += 1
            rest = use
            nex = now_a[-1]
            end = m
            while rest:
                val = nex
                start = bl(now_a, val)
                if start != 0:
                    nex = now_a[start-1]
                for i in range(start, end):
                    if now_a[i] > val:
                        break
                    elif now_a[i] == 1:
                        cnt -= 1
                    now_a[i] -= 1
                    rest -= 1
                    if rest == 0:
                        break
                end = start
    for i in ans_list[::-1]:
        print(i)


main()
